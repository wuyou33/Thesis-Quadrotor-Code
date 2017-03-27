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

xdes = [0;0;0];
b1d = [1;0;0];

% Attitude mode 0
% Position mode 1
mode = 1;

%% Uncertainties

Deltax = [-0.5; 0.2; 1]; %Goodarzi2013a
DeltaR = [0.2; -0.1; 0.02]; %Goodarzi2013a

%% Constants
m      = 4.34; %Lee2010 %weight bebop 420 g
Ixx    = 0.0820; %Lee2010
Iyy    = 0.0845; %Lee2010
Izz    = .1377; %Lee2010
I      = diag([Ixx Iyy Izz]); %Goodarzi2014
ctauf = 8.004e-3; %Lee2010c

b      = 0.1; %gok
d      = 0.1; %gok
Ir     = 0.5; %gok
l      = 0.315; %Lee2010 %wingspan bebop 248 mm
g      = 9.81;

e3 = [0;0;1];

fsat = 1000;

c_der = inf;

%% Initial Conditions
x0      = 0;
y0      = 0;
z0      = 0;
dx0     = 0;
dy0     = 0;
dz0     = 0;
p0      = 0;
q0      = 0;
r0      = 0;

% degrees
phi0    = 0;
theta0  = 0;
psi0    = 0;

Rinit = [1      0       0;
         0 -.9995 -0.0314;
         0 0.0314 -0.9995];
    

% phi = 10;
% theta = 0;
% psi = 0;
% 
% Rz = [cosd(psi) sind(psi) 0; 
%      -sind(psi) cosd(psi) 0; 
%       0 0 1];
% Ry = [cosd(theta) 0 -sind(theta);
%       0 1 0;
%       sin(theta) 0 cosd(theta)];
% Rx = [1 0 0; 
%       0 cosd(phi) sind(phi); 
%       0 -sind(phi) cosd(phi)];  
% Rzyx = (Rx*Ry*Rz);
% Rinit = Rzyx;


%% Gains

kx = 16*m;
kv = 5.6*m;

kR_phi       = 8.81; %Lee2010
kR_theta     = 0.5;
kR_psi       = 0.5;
% kR           = diag([kR_phi;kR_theta;kR_psi]);
kR = kR_phi*eye(3);
% kR = 8.81;

kOmega_phi   = 2.54; %Lee2010
kOmega_theta = 0.5;
kOmega_psi   = 0.5;
% kOmega       = diag([kOmega_phi;kOmega_theta;kOmega_psi]);
kOmega = kOmega_phi*eye(3);
% kOmega = 2.54;

open('QRsim')
sim('QRsim')

R0.signals.values(:,:,1)

%% Plots

t = simout.time;
pos = simout.signals.values(1:3,:);
vel = simout.signals.values(4:6,:);
acc = simout.signals.values(7:9,:);
Omega = simout.signals.values(10:12,:);
dOmega = simout.signals.values(13:15,:);
f = simout.signals.values(16,:);
M = simout.signals.values(17:19,:);
omegarot = simout.signals.values(20:23,:);
fi = simout.signals.values(24:27,:);

figure
subplot(8,1,[1,2])
plot(t,f)
legend('f')
subplot(8,1,[3,4])
plot(t,M)
legend('\tau_\phi','\tau_\theta','\tau_\psi')
subplot 815
plot(t,fi(1,:))
legend('f_1')
subplot 816
plot(t,fi(2,:))
legend('f_2')
subplot 817
plot(t,fi(3,:))
legend('f_3')
subplot 818
plot(t,fi(4,:))
legend('f_4')


figure
subplot 311
plot(t,pos)
legend('x','y','z')
subplot 312
plot(t,vel)
subplot 313
plot(t,acc)
suptitle('Position/Velocity/Acceleration')

figure
plot(t,pos,'linewidth',2)
h_suptitle = suptitle('QR Position');
set(h_suptitle,'FontSize',30);
h_legend = legend('x','y','z','Location','Northwest');
set(h_legend,'FontSize',25);

figure
subplot 211
plot(t,Omega)
legend('p','q','r')
subplot 212
plot(t,dOmega)
suptitle('Omega/dOmega')


figure
errorfunc = simouterror.signals.values;
plot(t,errorfunc,'linewidth',2)
h_suptitle = suptitle('Error function');
set(h_suptitle,'FontSize',30);
h_legend = legend('\Psi(R,R_d)');
set(h_legend,'FontSize',25);
% ,'Position',[.8,.7,.1,.1]

figure
for j=1:3
    for n=1:3
        p=(j-1)*3+n;
        subplot(3,3,p)
        Rplot = reshape(R.signals.values(j,n,:),[length(R.signals.values),1]);
        Rdesplot = reshape(Rdes.signals.values(j,n,:),[length(Rdes.signals.values),1]);        
        hold on
        axis([0 t(end) -1.2 1.2])
        plot(t,Rplot,'linewidth',2)
        plot(t,Rdesplot,'r--','linewidth',2)
    end
end
h_suptitle = suptitle('R and R_d \in\Re^{3\times3}');
set(h_suptitle,'FontSize',30);
h_legend = legend('R','R_d');
set(h_legend,'FontSize',25,'Position',[.8,.8,.1,.1]);

% figure
% subplot 311
% plot(t,R.signals.values(1,1,:))
% subplot 312
% plot(t,R.signals.values(2,:,:))
% subplot 313
% plot(t,R.signals.values(3,:,:))
