clear; clc; close all;

%% Settings
% Warning: Using a default value of 0.2 for maximum step size.  The simulation step size will be
% equal to or less than this value.  You can disable this diagnostic by setting 'Automatic solver
% parameter selection' diagnostic to 'none' in the Diagnostics page of the configuration
% parameters dialog
% >> Changed to 'none'

% The 'Array' format for saving outputs to the workspace requires all signals connected to the
% root outports to be scalar or 1-D arrays. For model 'QRsim' set the Format option in the
% 'Data Import/Export' page of the Configuration Parameters dialog to either 'Structure' or 'Structure with time'.
% >> Changed to 'Structure with time'

%% Input signals

% Position QR mode 0
% Attitude QR mode 1

% QRL QR Attitude Controlled mode 2
% QRL Load Attitude Controlled mode 3
% QRL Load Position Controlled mode 4

mode      = 4;

animation = 1;
plots     = 0;

Tsim_end  = 20;
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

T0 = 5; %Time period of oscillation of load

% xLd = [zeros(1,length(t)); sin(2*pi*t/T0); zeros(1,length(t))];
b1d = [1; 0; 0];
Rd  = eye(3);
qd  = [0; 0; -1];
% qd  = [0; 0; 1]; %inverted pendulum


%% Constants
mQ     = 4.34; %Lee2010 %weight bebop 420 g
Ixx    = 0.0820; %Lee2010
Iyy    = 0.0845; %Lee2010
Izz    = 0.1377; %Lee2010
I      = diag([Ixx Iyy Izz]); %Tang2014
lamb_m = min(eig(I));
lamb_M = max(eig(I));
ctauf  = 8.004e-3; %Lee2010c

% mL     = 0.045; %Praveen
% lL         = 1.12; %Praveen
mL     = 0.1;
lL     = 0.7;

b      = 0.1; %gok thrust factor
d      = 0.1; %gok drag factor
Ir     = 0.5; %gok
l      = 0.315; %Lee2010 %wingspan bebop 248 mm

g      = 9.81;
e3     = [0;0;1];

fc     = (mQ+mL)*g;
fsat   = 60*[0 1];
Msat   = 5*[-1 1];

%% Initial Conditions

phiQ0deg   = 0;
thetaQ0deg = 0;
psiQ0deg   = 0;

phiL0deg   = 0;
thetaL0deg = 0;
phiL0      = deg2rad(phiL0deg);
thetaL0    = deg2rad(thetaL0deg);
psiL0      = 0;

phiQ0      = deg2rad(phiQ0deg);
thetaQ0    = deg2rad(thetaQ0deg);
psiQ0      = deg2rad(psiQ0deg);
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

xL0        = 0;
yL0        = 0;
zL0        = 0;
dxL0       = 0;
dyL0       = 0;
dzL0       = 0;

pL0        = 0;
qL0        = 0;
rL0        = 0;

dq0        = [0;0;0];
omega0     = [0;0;0];

Rz         = [cos(psiL0) -sin(psiL0) 0;
                sin(psiL0) cos(psiL0) 0;
                0 0 1];
Ry         = [cos(thetaL0) 0 sin(thetaL0);
                0 1 0;
                -sin(thetaL0) 0 cos(thetaL0)];
Rx         = [1 0 0;
                0 cos(phiL0) -sin(phiL0);
                0 sin(phiL0) cos(phiL0)];
Rzyx       = (Rx*Ry*Rz);
q0         = Rzyx*-e3;

%% Gains

fgain = 1;

eps = 0.9; % 0<eps<1
psi_1 = .9; % Constant Psiq(0)<Psi_1<1 Lee2010 
exLmax = 5; %Fixed constant

% Gains QR Attitude
facR = 1*8;
kR = 8.81*facR; %Lee2010
% kOmega = 2.54*Rfac; %Lee2010
% kR = 5*Rfac;
kOmega = 2.4*facR;

% Gains Load Attitude
facq = 3*3;
kq = 10*facq;
komega = 6*facq;

% Gains Load Position
facx = 3*1.3;
kpx = 13.6*facx;
% kdx = 5.9*facx;
kdx = 6*facx;

% Save gains in mat-files
savegain  = 0;

if savegain == 1
    foldername = 'C:\Users\Nam\Documents\Git\Thesis-Quadrotor-Code\NamMatlab\QRL\GainFiles\';
    
    comment = 'Circle X-Y. CF3';
    
    for nfile = 1:100
        savename = strcat(foldername,num2str(nfile),'.mat');
                
        if exist(savename,'file') == 0
            save(savename,'comment','facR','kR','kOmega','facq','kq','komega','facx','kpx','kdx','omega_n_xL','omega_n_q','omega_n_R' )
            break
        end
    end
end

% Simulation

% % Check if Simulink is already open to avoid re-opening
% openModels = find_system('SearchDepth', 0);
% if strmatch('QRLsim',openModels)>0
%     open('QRLsim')
% end

loadpath = 'C:\Users\Nam\Documents\Git\Thesis-Quadrotor-Code\NamMatlab\QRL\GainFiles\';
loadfile = strcat(loadpath,'3','.mat');
load(loadfile)

% Command Filter Low Pass filter 2*pi* 
omega_n_xL = 2*pi*.5;
omega_n_q = 2*pi*.8;
omega_n_R = 2*pi*.05;

sim('QRLsim')

% Dataconversion

t        = simoutL.time;

posL     = simoutL.signals.values(:,1:3)';
velL     = simoutL.signals.values(:,4:6)';
accL     = simoutL.signals.values(:,7:9)';

angleL   = simoutL1.signals.values(:,1:3);
OmegaL   = simoutL1.signals.values(:,4:6);

angleQ   = simoutL2.signals.values(:,1:3);
OmegaQ   = simoutL2.signals.values(:,4:6);
dOmegaQ  = simoutL2.signals.values(:,7:9);

f        = simoutL3.signals.values(:,1);
M        = simoutL3.signals.values(:,2:4)';
omegarot = simoutL3.signals.values(:,5:8)';
fi       = simoutL3.signals.values(:,9:12)';

q        = simoutq.signals.values(:,1:3)';
dq       = simoutq.signals.values(:,4:6)';
ddq      = simoutq.signals.values(:,7:9)';

eq       = simouteq.signals.values(:,1:3);
edq      = simouteq.signals.values(:,4:6);
eR       = simouterrorR.signals.values(:,1:3);
eOmega   = simouterrorR.signals.values(:,4:6);
Psiq     = simoutPsiq.signals.values(:,1);
PsiR     = simoutPsiR.signals.values(:,1);

xLd      = simoutxLd.signals.values(:,1:3)';
dxLd     = simoutxLd.signals.values(:,4:6)';
ddxLd    = simoutxLd.signals.values(:,7:9)';

exL      = simoutexL.signals.values(:,1:3)';

F        = reshape(simoutF.signals.values,3,length(t));
qcplot   = reshape(simoutqc.signals.values,[3,length(simoutqc.signals.values)]);

posQ     = posL - q*lL;

%% Conditions check

% Prop.1 Sreenath2013b
if PsiR(1) >= 2
    error('PsiR(0) >= 2')
end
if norm(eOmega(1),2)^2 >= 2/lamb_M * kR/eps^2 * (2-PsiR(1))
    error('eOmega(0) too big')
end

% Prop.2 Sreenath2013b
if mode >= 3
    if Psiq(1) >= 2
        error('Psiq(0) >= 2')
    end
    if norm(edq(1),2)^2 >= 2/(mQ*lL)*kq*(2-Psiq(1))
        error('edq(0) too big')
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
    if norm(edq(1,:))^2 >= 2/(mQ*lL)*kq*(psi_1-Psiq(1))
        error('edq(0) too big. Prop.3 Sreenath2013b')
    end
end

%% Plots
if plots == 1
    QRLplots
end

%% Animation
if animation == 1
    QRLanimation
end