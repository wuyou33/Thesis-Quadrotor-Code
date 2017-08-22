% clear; clc; close all;

%% Overview
% QR - Quadrotor
% QRL - Quadrotor-Load
% R - Rotation Matrix
% q - Load attitude: unit vector from QR to Load
% eR - QR Attitude error
% eOmega - QR Angular velocity error
% eq - Load Attitude error
% eomega - Load Angular velocity error
% ex - Load position error
% ev - Load velocity error
% 
% Quadrotor Parameters
% xQ/dxQ/ddxQ - QR position/velocity/acceleration
% mQ - QR mass
% 
% Load Parameters
% xL/dxL/ddxL - Load position/velocity/acceleration
% mL - Load mass

%% Matlab Settings
% Warning: Using a default value of 0.2 for maximum step size.  The simulation step size will be
% equal to or less than this value.  You can disable this diagnostic by setting 'Automatic solver
% parameter selection' diagnostic to 'none' in the Diagnostics page of the configuration
% parameters dialog
% >> Changed to 'none'

% The 'Array' format for saving outputs to the workspace requires all signals connected to the
% root outports to be scalar or 1-D arrays. For model 'QRsim' set the Format option in the
% 'Data Import/Export' page of the Configuration Parameters dialog to either 'Structure' or 'Structure with time'.
% >> Changed to 'Structure with time'


%% Settings
animation    = 0; % Turn animation on/off

plots        = 1; % Turn plot generation + save matfiles on/off
loadgain     = 0;
nameloadgain = 'Gains78'; %Gain file to load


%% Input signals

% CONTROL MODE
% QR Position Controlled mode 0
% QR Attitude Controlled mode 1
% QRL QR Attitude Controlled mode 2
% QRL Load Attitude Controlled mode 3
% QRL Load Position Controlled mode 4
mode      = 4;

% LOAD ATTITUDE MODE
% Normal -1
% Inverted 1
qmode     = -1;

Tsim_end  = 30;
Tsim_s    = 0.01;

switch mode
    case 2
        modename = 'QRL QR Attitude Controlled Mode';
        modecode = 'QRATTQRL';
        disp(modename)
    case 3
        modename = 'QRL Load Attitude Controlled Mode';
        modecode = 'LATTQRL';
        disp(modename)
    case 4
        modename = 'QRL Load Position Controlled Mode';
        modecode = 'LPOSQRL';
        disp(modename)
    otherwise
        disp('No Control Mode selected');
end

% T0 = 3; %Time period of oscillation of load

b1d = [1; 0; 0];
Rd  = eye(3);
qd  = [0; 0; qmode];


%% Constants
% Model parameters

% Parrot Bebop 1
% Weight 410 g 
% Max speed 13 m/s
% Max inclination 30 deg
% Max climb speed 2.5 m/s

% Parrot Bebop 2
% Weight 500 g 
% Max speed 18 m/s
% Max inclination 35 deg
% Max climb speed 6 m/s

% mQ     = 4.34; %Lee2010
% l      = 0.315; %Lee2010 
% Ixx    = 0.0820; %Lee2010
% Iyy    = 0.0845; %Lee2010
% Izz    = 0.1377; %Lee2010

% mQ     = 0.7; %Becker
% Ixx    = 4.6e-3; %Becker
% Iyy    = 4.6e-3; %Becker
% Izz    = 8.2e-3; %Becker
% I      = diag([Ixx Iyy Izz]);
% mL     = 0.2; %Becker
% L     = 0.7; %Becker

% mL     = 0.045; %Praveen
% lL         = 1.12; %Praveen

mQ    = 0.4; %Cornelis2014
l     = 0.126; %Cornelis2014
Ixx   = 0.00223; %Cornelis2014
Iyy   = 0.00299; %Cornelis2014
Izz   = 0.00480; %Cornelis2014
I     = diag([Ixx Iyy Izz]); 
mL    = 0.1;
L     = 0.7;

b      = 0.1; %gok thrust factor
d      = 0.1; %gok drag factor
Ir     = 0.5; %gok
ctauf = 8.004e-3; %Lee2010c

g      = 9.81;
e3     = [0;0;1];

% fc     = (mQ+mL)*g;

%% Initial Conditions QR
% Initial conditions of the QR attitude

phiQ0      = deg2rad(0);
thetaQ0    = deg2rad(0);
psiQ0      = deg2rad(0);
pQ0        = 0;
qQ0        = 0;
rQ0        = 0;

Rz         = [cos(psiQ0) -sin(psiQ0) 0;
                sin(psiQ0) cos(psiQ0) 0;
                0 0 1];
Ry         = [cos(thetaQ0) 0 sin(thetaQ0);
                0 1 0;
                -sin(thetaQ0) 0 cos(thetaQ0)];
Rx         = [1 0 0;
                0 cos(phiQ0) -sin(phiQ0);
                0 sin(phiQ0) cos(phiQ0)];
Rzyx       = (Rx*Ry*Rz);
R0         = Rzyx;

%% Initial Conditions Load
% Initial conditions of the load attitude and load position

dxL0       = 0;
dyL0       = 0;
dzL0       = 0;

phiL0      = deg2rad(0);
thetaL0    = deg2rad(0);
psiL0      = 0;

pL0        = 0;
qL0        = 0;
rL0        = 0;

dq0        = [0;0;0];
% omega0     = [0;0;0];

Ry         = [cos(thetaL0) 0 sin(thetaL0);
                0 1 0;
                -sin(thetaL0) 0 cos(thetaL0)];
Rx         = [1 0 0;
                0 cos(phiL0) -sin(phiL0);
                0 sin(phiL0) cos(phiL0)];
Rzyx       = (Rx*Ry);
q0         = Rzyx*e3*qmode;

xL0        = q0(1)*L;
yL0        = q0(2)*L;
zL0        = L+q0(3)*L;

% x0 = [xL0;yL0;zL0];

%% Gains 
% Controller gains

    epsi         = 0.99; % 0<epsi<1
if loadgain == 1
    foldername = 'C:\Users\Nam\Documents\Git\Thesis-Quadrotor-Code\NamMatlab\QRL\MatlabImages\';
    load(strcat(foldername,nameloadgain));
elseif loadgain == 0
    eps         = 0.99; % 0<eps<1
%     
%     Gains QR Attitude
    facR        = 1;
%     kR          = 9.81*facR; %Lee2010
    kR          = 0.9; %Lee2010
    kOmega      = 0.1;
%     
%     Gains Load Attitude
    facq        = 1;
    kq          = 3.9;
    komega      = 2;
%     
%     Gains Load Position
    facx        = 1; %4;
    kpx         = 6;%20.4
    kdx         = 2.75;%11.7
%     
%     Step block parameters
    stept   = 1;
    stepamp = 0.25;
%     
%     Command Filter Low Pass filter 3th order
    omega_n1_xL  = 25;
%     omega_n2_xL  = 60;
%     omega_n1_CFP = 2;
%     omega_n2_CFP = 2;
    zeta_xL      = 0.98;
    omega_n1_q   = 25;
%     omega_n2_q   = 50;
    zeta_q       = 0.98;
    omega_n1_R   = 30;
%     omega_n2_R   = 80;
    zeta_R       = 0.98;

fsat   = 4*1.96*[1 -1]; %1.96 N max thrust per rotor %Cornelis2014
Msat   = 2*l*1.96*[1 -1];

end

% Simulation
LQRrunfile
sim('QRLsim');

%% Initial conditions check
% This section checks whether the initial conditions are met. Sreenath 2013

Psiq   = simoutPsiq.signals.values(:,1);
PsiR   = simoutPsiR.signals.values(:,1);
eOmega = simouterrorR.signals.values(:,4:6);
edq    = simouteq.signals.values(:,4:6);
exL    = simoutexL.signals.values(:,1:3)';

lamb_m = min(eig(I));
lamb_M = max(eig(I));
psi_1  = .9; % Constant Psiq(0)<Psi_1<1 Lee2010 
exLmax = 5; %Fixed constant

% Prop.1 Sreenath2013b
if PsiR(1) >= 2
    error('PsiR(0) >= 2');
end
if norm(eOmega(1),2)^2 >= 2/lamb_M * kR/eps^2 * (2-PsiR(1))
    error('eOmega(0) too big')
end

% Prop.2 Sreenath2013b
if mode >= 3
    if Psiq(1) >= 2
        error('Psiq(0) >= 2');
    end
    if norm(edq(1),2)^2 >= 2/(mQ*L)*kq*(2-Psiq(1))
        error('edq(0) too big');
    end
end

% Prop.3 Sreenath2013b
if mode == 4
    if Psiq(1) >= psi_1
        error('Psiq(0) >= psi_1')
    end
    if norm(exL(:,1)) >= exLmax
        error('norm(exL(:,1)) >= exLmax')
    end
    if norm(edq(1,:))^2 >= 2/(mQ*L)*kq*(psi_1-Psiq(1))
        error('edq(0) too big. Prop.3 Sreenath2013b')
    end
end

%% Plots
casename     = 'C';
comment      = strcat('case',casename,'-Bebop-LQR',date); % comment added to save file
comment2     = ('wokkel-CFv2'); % comment added to save file
foldername = 'C:\Users\Nam\Documents\Git\Thesis-Quadrotor-Code\NamMatlab\QRL\MatlabImages\';

if plots == 1
    QRLplots;
    QRLplotsLQR;
end
close all
%% Animation
if animation == 1
%     QRLanimation
%     QRLanimationLQR
    QRLanimationboth
end