%% Dataconversion

t            = simoutL.time;

lqrposL      = lqrsimoutL.signals.values(:,1:3)';
posL         = simoutL.signals.values(:,1:3)';
velL         = simoutL.signals.values(:,4:6)';
accL         = simoutL.signals.values(:,7:9)';

lqrangleL    = wrapTo180((lqrsimoutL1.signals.values(:,1:2)));
angleL       = wrapTo180((simoutL1.signals.values(:,1:3)));
OmegaL       = rad2deg(simoutL1.signals.values(:,4:6));

r11          = reshape(simoutR.signals.values(1,1,:),1,length(t));
r21          = reshape(simoutR.signals.values(2,1,:),1,length(t));
r31          = reshape(simoutR.signals.values(3,1,:),1,length(t));
r32          = reshape(simoutR.signals.values(3,2,:),1,length(t));
r33          = reshape(simoutR.signals.values(3,3,:),1,length(t));

psi          = atan(r21./r11);
theta        = atan(-r31./sqrt(r32.^2+r33.^2));
phi          = atan(r32./r33);

angleQ       = rad2deg([phi;theta;psi])';
lqrangleQ    = lqrsimoutL2.signals.values(:,1:3);

OmegaQ       = rad2deg(simoutL2.signals.values(:,4:6));
dOmegaQ      = rad2deg(simoutL2.signals.values(:,7:9));

f            = simoutL3.signals.values(:,1);
M            = simoutL3.signals.values(:,2:4)';
omegarot     = simoutL3.signals.values(:,5:8)';
fi           = simoutL3.signals.values(:,9:12)';

q            = simoutq.signals.values(:,1:3)';
dq           = simoutq.signals.values(:,4:6)';
ddq          = simoutq.signals.values(:,7:9)';

eq           = simouteq.signals.values(:,1:3);
edq          = simouteq.signals.values(:,4:6);
eR           = simouterrorR.signals.values(:,1:3);
eOmega       = simouterrorR.signals.values(:,4:6);
Psiq         = simoutPsiq.signals.values(:,1);
PsiR         = simoutPsiR.signals.values(:,1);

xLd          = simoutxLd.signals.values(:,1:3)';
dxLd         = simoutxLd.signals.values(:,4:6)';
ddxLd        = simoutxLd.signals.values(:,7:9)';

exL          = simoutexL.signals.values(:,1:3)';
edxL         = simoutexL.signals.values(:,4:6)';
lqrexL       = lqrsimoutexL.signals.values(:,1:3)';

% F            = reshape(simoutF.signals.values,3,length(t));
% F            = simoutF.signals.values(:,10:12);
qcplot       = reshape(simoutqc.signals.values,[3,length(simoutqc.signals.values)]);

posQ         = posL - q*L;
lqrposQd     = lqrsimoutL4.signals.values(:,1:3);
lqrposQ      = lqrsimoutL3.signals.values(:,1:3);

%%
    lfont = 18; %Legend Fontsize
    afont = 16; %Axis Fontsize
    labfont = 20; %Label Fontsize
    supfont = 25; %Suptitle Fontsize
    
    foldername = 'C:\Users\Nam\Documents\Git\Thesis-Quadrotor-Code\NamMatlab\QRL\MatlabImages\';

for nfile = 40:100

%     savename = strcat(foldername,modecode,num2str(nfile),'.mat');
%     if exist(savename,'file') == 0
%         disp(nfile)
%         break
%     end
    
    savename = strcat(foldername,'Gains',num2str(nfile),'.mat');
    if exist(savename,'file') == 0
        save(savename,'comment','comment2','facR','kR','kOmega','facq','kq','komega',...
            'facx','kpx','kdx','omega_n1_xL','omega_n2_xL','omega_n1_q',...
            'omega_n2_q','omega_n1_R','omega_n2_R','omega_n1_CFP','omega_n2_CFP','zeta_xL','zeta_q',...
            'zeta_R','LQRA','LQRB','LQRC','LQRD','K','LQRQ','LQRR');
        save(strcat(num2str(nfile),'.txt'),'kR','kOmega','kq','komega','kpx','kdx','mQ','mL','I','l','L','-ascii');
        
        % Write to Excel
        excelname = 'parameters.xlsx';
%         exceldata = {'mQ',mQ;'mL',mL;'l',l;'L',L;'Ixx',Ixx;'Iyy',Iyy;'Izz',Izz;'kR',kR;'kOmega',kOmega;'kq',kq;'komega',komega;'kpx',kpx;'kdx',kdx};
        par = {'mQ';'mL';'l';'L';'Ixx';'Iyy';'Izz';'kR';'kOmega';'kq';'komega';'kpx';'kdx'};
        val = {mQ;mL;l;L;Ixx;Iyy;Izz;kR;kOmega;kq;komega;kpx;kdx};
        cfpar = {'omega_n1_xL';'omega_n2_xL';'omega_n1_CFP';'omega_n2_CFP';'zeta_xL';'omega_n1_q';'omega_n2_q';'zeta_q';'omega_n1_R';'omega_n2_R';'zeta_R'};
        cfval = {omega_n1_xL;omega_n2_xL;omega_n1_CFP;omega_n2_CFP;zeta_xL;omega_n1_q;omega_n2_q;zeta_q;omega_n1_R;omega_n2_R;zeta_R};        
        exceldata = [{'filenumber'},{nfile};par,val;cfpar,cfval];
        sheet = num2str(nfile);
        xlswrite(excelname,exceldata,sheet)
        break
    end
end

save(strcat(foldername,modecode,num2str(nfile),'.mat'))
save(strcat(foldername,modecode,num2str(nfile),comment,'.mat'))

   

%% Inputs

filename = 'f';
figure('Name',filename)
h_suptitle = suptitle(strcat(filename,' $[N]$'));
set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
subplot(6,1,[1,2])
plot(t,f,'Linewidth',2)
ylabel('\boldmath$f_{total}$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 613
plot(t,fi(1,:),'Linewidth',2)
ylabel('\boldmath$f_1$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 614
plot(t,fi(2,:),'Linewidth',2)
ylabel('\boldmath$f_2$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 615
plot(t,fi(3,:),'Linewidth',2)
ylabel('\boldmath$f_3$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 616
plot(t,fi(4,:),'Linewidth',2)
ylabel('\boldmath$f_4$','FontSize',labfont,'Interpreter','latex')
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')

filename = 'M';
figure('Name',filename)
h_suptitle = suptitle(strcat(filename,' $[Nm]$'));
set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
plot(t,M,'Linewidth',2)
hl = legend('\boldmath$\tau_\phi$','\boldmath$\tau_\theta$','\boldmath$\tau_\psi$');
set(hl,'Interpreter','latex','FontSize',lfont)
ylabel('\boldmath$M$','FontSize',labfont,'Interpreter','latex')
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')

%%
filename = 'Lpos';
figure('Name',filename)
h_sup = suptitle('Load Pos./Vel./Acc.');
set(h_sup,'FontSize',supfont,'Interpreter','latex');
subplot 311
plot(t,posL,'Linewidth',2)
hl = legend('\boldmath$x$','\boldmath$y$','\boldmath$z$');
set(hl,'Interpreter','latex','FontSize',lfont);
ylabel('\boldmath$[m]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 312
plot(t,velL,'Linewidth',2)
hl = legend('\boldmath$\dot{x}$','\boldmath$\dot{y}$','\boldmath$\dot{z}$');
set(hl,'Interpreter','latex','FontSize',lfont);
ylabel('\boldmath$[m/s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 313
plot(t,accL,'Linewidth',2)
hl = legend('\boldmath$\ddot{x}$','\boldmath$\ddot{y}$','\boldmath$\ddot{z}$');
set(hl,'Interpreter','latex','FontSize',lfont);
ylabel('\boldmath$[m/s^2]$','FontSize',labfont,'Interpreter','latex')
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
hLPosOverview = gcf;
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')

if mode==4
   
filename = 'xL';
figure('Name',filename)
h_sup = suptitle('Load Position $[m]$');
set(h_sup,'FontSize',supfont,'Interpreter','latex');
subplot 311
plot(t,posL(1,:),t,xLd(1,:),'r--','Linewidth',2)
hl = legend('\boldmath$x_L$','\boldmath$x_{L,d}$');
ylabel('\boldmath$x$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 312
plot(t,posL(2,:),t,xLd(2,:),'r--','Linewidth',2)
ylabel('\boldmath$y$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 313
plot(t,posL(3,:),t,xLd(3,:),'r--','Linewidth',2)
ylabel('\boldmath$z$','FontSize',labfont,'Interpreter','latex')
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
set(hl,'Interpreter','latex','FontSize',lfont);
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')  


filename = 'xLdes';
figure('Name',filename)
h_sup = suptitle('Desired Load Position $[m]$');
set(h_sup,'FontSize',supfont,'Interpreter','latex');
subplot 311
plot(t,xLd(1,:),'r--','Linewidth',2)
hl = legend('\boldmath$x_{L,d}$');
ylabel('\boldmath$x$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 312
plot(t,xLd(2,:),'r--','Linewidth',2)
ylabel('\boldmath$y$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 313
plot(t,xLd(3,:),'r--','Linewidth',2)
ylabel('\boldmath$z$','FontSize',labfont,'Interpreter','latex')
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
set(hl,'Interpreter','latex','FontSize',lfont);
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png') 

filename = 'dxLdes';
figure('Name',filename)
h_sup = suptitle('Desired Load Velocity $[m/s]$');
set(h_sup,'FontSize',supfont,'Interpreter','latex');
subplot 311
plot(t,dxLd(1,:),'r--','Linewidth',2)
hl = legend('\boldmath$\dot{x}_{L,d}$');
ylabel('\boldmath$\dot{x}$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 312
plot(t,dxLd(2,:),'r--','Linewidth',2)
ylabel('\boldmath$\dot{y}$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 313
plot(t,dxLd(3,:),'r--','Linewidth',2)
ylabel('\boldmath$\dot{z}$','FontSize',labfont,'Interpreter','latex')
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
set(hl,'Interpreter','latex','FontSize',lfont);
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')

filename = 'ddxLdes';
figure('Name',filename)
h_sup = suptitle('Desired Load Acceleration $[m/s^2]$');
set(h_sup,'FontSize',supfont,'Interpreter','latex');
subplot 311
plot(t,ddxLd(1,:),'r--','Linewidth',2)
hl = legend('\boldmath$\ddot{x}_{L,d}$');
ylabel('\boldmath$\ddot{x}$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 312
plot(t,ddxLd(2,:),'r--','Linewidth',2)
ylabel('\boldmath$\ddot{y}$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 313
plot(t,ddxLd(3,:),'r--','Linewidth',2)
ylabel('\boldmath$\ddot{z}$','FontSize',labfont,'Interpreter','latex')
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
set(hl,'Interpreter','latex','FontSize',lfont);
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')

filename = 'xLdesplot';
figure('Name',filename)
h_sup = suptitle('Desired Load Position');
set(h_sup,'FontSize',supfont,'Interpreter','latex');
hold on
plot3(xLd(1,:),xLd(2,:),xLd(3,:),'LineWidth',3)
plot3(xLd(1,1),xLd(2,1),xLd(3,1),'go','LineWidth',3)
plot3(xLd(1,end),xLd(2,end),xLd(3,end),'rd','LineWidth',3)
grid on
hold off
hl = legend('\boldmath$x_{L,d}$','Start','End');
view(-27,16)
xlabel('\boldmath$x [m]$','FontSize',labfont,'Interpreter','latex')
ylabel('\boldmath$y [m]$','FontSize',labfont,'Interpreter','latex')
zlabel('\boldmath$z [m]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
set(hl,'Interpreter','latex','FontSize',lfont);
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')  

end
      

% filename = 'QRpos';
% figure('Name',filename)
% h_sup = suptitle('QR Pos./Vel./Acc.');
% set(h_sup,'FontSize',supfont,'Interpreter','latex');
% subplot 311
% plot(t,posQ,'Linewidth',2)
% hl = legend('\boldmath$x$','\boldmath$y$','\boldmath$z$');
% ylabel('\boldmath$[m]$','FontSize',labfont,'Interpreter','latex')
% xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% set(hl,'Interpreter','latex','FontSize',lfont);
% % subplot 312
% % plot(t,velQ,'Linewidth',2)
% % hl = legend('$\dot{x}$','$\dot{y}$','$\dot{z}$');
% % set(hl,'Interpreter','latex','FontSize',lfont);
% % ylabel('vel [m/s]','FontSize',labfont)
% % subplot 313
% % plot(t,accQ,'Linewidth',2)
% % hl = legend('$\ddot{x}$','$\ddot{y}$','$\ddot{z}$');
% % set(hl,'Interpreter','latex','FontSize',lfont);
% % ylabel('acc [m/s^2]','FontSize',labfont)
% saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')

% filename = 'QRLpos';
% figure('Name',filename)
% h_suptitle = suptitle('QR-Load Position');
% set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
% subplot 311
% hold on
% plot(t,posL(1,:),t,posQ(1,:),'Linewidth',2);
% ylabel('\boldmath$x [m]$','FontSize',labfont,'Interpreter','latex');
% set(gca,'FontSize',afont);
% hl = legend('\boldmath$x_L$','\boldmath$x_Q$');
% subplot 312
% hold on
% plot(t,posL(2,:),t,posQ(2,:),'Linewidth',2);
% ylabel('\boldmath$y [m]$','FontSize',labfont,'Interpreter','latex');
% set(gca,'FontSize',afont);
% set(hl,'Interpreter','latex','FontSize',lfont,'Interpreter','latex');
% subplot 313
% hold on
% plot(t,posL(3,:),t,posQ(3,:),'Linewidth',2);
% xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
% ylabel('\boldmath$z [m]$','FontSize',labfont,'Interpreter','latex');
% set(gca,'FontSize',afont);
% set(hl,'Interpreter','latex','FontSize',lfont,'Position',[.8,.8,.1,.1]);
% saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')

%%
filename = 'QRang';
figure('Name',filename)
h_sup = suptitle('QR Angle');
set(h_sup,'FontSize',supfont,'Interpreter','latex');
subplot 211
plot(t,angleQ(:,1),t,angleQ(:,2),'Linewidth',2)
hl = legend('\boldmath$\phi_Q$','\boldmath$\theta_Q$');
ylabel('\boldmath$[^\circ]$','FontSize',labfont,'Interpreter','latex')
set(hl,'Interpreter','latex','FontSize',lfont);
set(gca,'color','none','FontSize',afont)
set(gca,'FontSize',afont);
subplot 212
plot(t,angleQ(:,3),'r','Linewidth',2)
hl = legend('\boldmath$\psi_Q$');
ylabel('\boldmath$[^\circ]$','FontSize',labfont,'Interpreter','latex')
set(hl,'Interpreter','latex','FontSize',lfont);
set(gca,'color','none','FontSize',afont)
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')

filename = 'QRvel';
figure('Name',filename)
h_sup = suptitle('QR $\Omega$/$\dot{\Omega}$');
set(h_sup,'FontSize',supfont,'Interpreter','latex');
subplot 211
plot(t,OmegaQ,'Linewidth',2)
hl = legend('\boldmath$p_Q$','\boldmath$q_Q$','\boldmath$r_Q$');
set(hl,'Interpreter','latex','FontSize',lfont);
ylabel('\boldmath$[^\circ/s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 212
plot(t,dOmegaQ,'Linewidth',2)
hl = legend('\boldmath$\dot{p}_Q$','\boldmath$\dot{q}_Q$','\boldmath$\dot{r}_Q$');
set(hl,'Interpreter','latex','FontSize',lfont);
ylabel('\boldmath$[^\circ/s^2]$','FontSize',labfont,'Interpreter','latex')
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')

filename = 'Lang';
figure('Name',filename)
h_sup = suptitle('Load Angle/$\Omega$');
set(h_sup,'FontSize',supfont,'Interpreter','latex');
subplot 311
% plot(t,angleL,'Linewidth',2)
% hl = legend('\boldmath$\phi_L$','\boldmath$\theta_L$','\boldmath$\psi_L$');
plot(t,angleL(:,1),t,angleL(:,2),'Linewidth',2)
hl = legend('\boldmath$\phi_L$','\boldmath$\theta_L$');
ylabel('\boldmath$[^\circ]$','FontSize',labfont,'Interpreter','latex')
set(hl,'Interpreter','latex','FontSize',lfont);
set(gca,'color','none','FontSize',afont)
subplot 312
% plot(t,OmegaL,'Linewidth',2)
% hl = legend('\boldmath$p_L$','\boldmath$q_L$','\boldmath$r_L$');
plot(t,OmegaL(:,1),t,OmegaL(:,2),'Linewidth',2)
hl = legend('\boldmath$p_L$','\boldmath$q_L$');
set(hl,'Interpreter','latex','FontSize',lfont);
ylabel('\boldmath$[^\circ/s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
% subplot 313
% plot(t,dOmegaL,'Linewidth',2)
% hl = legend('$\dot{p}_L$','$\dot{q}_L$','$\dot{r}_L$');
% set(hl,'Interpreter','latex','FontSize',lfont);
% ylabel('\boldmath$acc [^\circ/s^2]$','FontSize',labfont,'Interpreter','latex')
% xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')

% figure
% plot(t,pos,'Linewidth',2)
% h_suptitle = suptitle('QR Position');
% set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
% hl = legend('$x$','$y$','$z$');
% set(hl,'Interpreter','latex','FontSize',lfont)

%% Rotation Matrix

filename = 'Rotations';
figure('Name',filename)
h_sup = suptitle('Rotation $R\in\Re^{3\times3}$');
set(h_sup,'FontSize',supfont,'Interpreter','latex');
for j=1:3
    for n=1:3
        k=(j-1)*3+n;
        subplot(3,3,k)
        Rplot = reshape(simoutR.signals.values(j,n,:),[length(simoutR.signals.values),1]);
        Rcplot = reshape(simoutRc.signals.values(j,n,:),[length(simoutRc.signals.values),1]);
        hold on
        axis([0 t(end) -1.1 1.1])
%         axis([0 4 -1.2 1.2])
        plot(t,Rplot,'Linewidth',2)
        plot(t,Rcplot,'r--','Linewidth',2)
        set(gca,'FontSize',afont);
        if k==8
            xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
        end
    end
end
switch mode
    case 2 % QRL Attitude Controlled Mode
        hl = legend('\boldmath$R$','\boldmath$R_d$');
    otherwise
        hl = legend('\boldmath$R$','\boldmath$R_c$');
end
set(hl,'Interpreter','latex','FontSize',lfont,'Position',[.8,.8,.1,.1]);
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')

%% q

filename = 'q';
figure('Name',filename)
h_suptitle = suptitle('Unit vector $q$ from QR to Load');
set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
plot(t,q,'LineWidth',2)

% hl = legend('$\vec{q}\cdot\vec{b}_1$','$\vec{q}\cdot\vec{b}_2$','$\vec{q}\cdot\vec{b}_3$');
switch mode
    case 3 % QRL Load Attitude Controlled Mode
        subplot 311
        plot(t,q(1,:),t,qcplot(1,:),'r--','Linewidth',2)
        ylabel('\boldmath$\vec{q}\cdot\vec{b}_1$','FontSize',labfont,'Interpreter','latex')
        set(gca,'FontSize',afont);
        subplot 312
        plot(t,q(2,:),t,qcplot(2,:),'r--','Linewidth',2)
        ylabel('\boldmath$\vec{q}\cdot\vec{b}_2$','FontSize',labfont,'Interpreter','latex')
        set(gca,'FontSize',afont);
        subplot 313
        plot(t,q(3,:),t,qcplot(3,:),'r--','Linewidth',2)
        ylabel('\boldmath$\vec{q}\cdot\vec{b}_3$','FontSize',labfont,'Interpreter','latex')
        set(gca,'FontSize',afont);
        hl = legend('\boldmath$\vec{q}$','\boldmath$\vec{q}_d$');        
    case 4 % QRL Load Position Controlled Mode
        subplot 311
        plot(t,q(1,:),t,qcplot(1,:),'r--','Linewidth',2)
        ylabel('\boldmath$\vec{q}\cdot\vec{b}_1$','FontSize',labfont,'Interpreter','latex')
        set(gca,'FontSize',afont);
        subplot 312
        plot(t,q(2,:),t,qcplot(2,:),'r--','Linewidth',2)
        ylabel('\boldmath$\vec{q}\cdot\vec{b}_2$','FontSize',labfont,'Interpreter','latex')
        set(gca,'FontSize',afont);
        subplot 313
        plot(t,q(3,:),t,qcplot(3,:),'r--','Linewidth',2)
        ylabel('\boldmath$\vec{q}\cdot\vec{b}_3$','FontSize',labfont,'Interpreter','latex')
        set(gca,'FontSize',afont);
        hl = legend('\boldmath$\vec{q}$','\boldmath$\vec{q}_c$');  
end
set(hl,'Interpreter','latex','FontSize',lfont,'Position',[.8,.8,.1,.1]);
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex');
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')

%% qplots

filename = 'qplots';
figure('Name',filename)
h_suptitle = suptitle('Unit vector $q$ from QR to Load');
set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
plot(t,q,'LineWidth',2)
subplot 311
plot(t,q,'LineWidth',2)
ylabel('\boldmath$q$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 312
plot(t,dq,'LineWidth',2)
ylabel('\boldmath$\dot{q}$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
subplot 313
plot(t,ddq,'LineWidth',2)
ylabel('\boldmath$\ddot{q}$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
hl = legend('\boldmath$\vec{b}_1$','\boldmath$\vec{b}_2$','\boldmath$\vec{b}_3$');  

set(hl,'Interpreter','latex','FontSize',lfont,'Position',[.8,.8,.1,.1]);
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex');
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')

%% Errors

filename = 'eR';
figure('Name',filename)
h_suptitle = suptitle('QR Attitude Error $\in TSO(3)$');
set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
subplot 211
plot(t,eR,'Linewidth',2)
ylabel('\boldmath$e_{R}$','FontSize',labfont,'Interpreter','latex');
set(gca,'FontSize',afont);
hl = legend('\boldmath$e_{R,1}$','\boldmath$e_{R,2}$','\boldmath$e_{R,3}$','FontSize',lfont);
set(hl,'Interpreter','latex','FontSize',lfont);
subplot 212
plot(t,eOmega,'Linewidth',2);
ylabel('\boldmath$e_{\Omega}$','FontSize',labfont,'Interpreter','latex');
set(gca,'FontSize',afont);
hl = legend('\boldmath$e_{\Omega,1}$','\boldmath$e_{\Omega,2}$','\boldmath$e_{\Omega,3}$','FontSize',lfont);
set(hl,'Interpreter','latex','FontSize',lfont);
xlabel('Time [s]','FontSize',labfont,'Interpreter','latex')
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')

filename = 'eq';
figure('Name',filename)
h_suptitle = suptitle('Load Attitude Error $\in TS^2$');
set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
subplot 211
plot(t,eq,'Linewidth',2);
ylabel('\boldmath$e_{q}$','FontSize',labfont,'Interpreter','latex');
set(gca,'FontSize',afont);
hl = legend('\boldmath$e_{q,1}$','\boldmath$e_{q,2}$','\boldmath$e_{q,3}$','FontSize',lfont);
set(hl,'Interpreter','latex','FontSize',lfont);
subplot 212
plot(t,edq,'Linewidth',2)
ylabel('\boldmath$e_{\dot{q}}$','FontSize',labfont,'Interpreter','latex');
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
hl = legend('\boldmath$e_{\dot{q},1}$','\boldmath$e_{\dot{q},2}$','\boldmath$e_{\dot{q},3}$','FontSize',lfont);
set(hl,'Interpreter','latex','FontSize',lfont);
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')

filename = 'exL';
figure('Name',filename)
h_suptitle = suptitle('Load Position Error $[m]$');
set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
subplot 211
plot(t,exL,'Linewidth',2)
ylabel('\boldmath$e_{x}$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
hl = legend('\boldmath$e_{x}$','\boldmath$e_{y}$','\boldmath$e_{z}$');
set(hl,'Interpreter','latex','FontSize',lfont);
subplot 212
plot(t,edxL,'Linewidth',2)
ylabel('\boldmath$e_{v}$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
hl = legend('\boldmath$e_{\dot{x}}$','\boldmath$e_{\dot{y}}$','\boldmath$e_{\dot{z}}$');
set(hl,'Interpreter','latex','FontSize',lfont);
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')  

%% Error functions
       
filename = 'PsiR';
figure('Name',filename)
h_suptitle = suptitle('QR Attitude Error function');
set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
plot(t,PsiR,'Linewidth',2)
ylabel('\boldmath$\Psi_R$','FontSize',labfont,'Interpreter','latex')
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')  

filename = 'Psiq';
figure('Name',filename)
h_suptitle = suptitle('Load Attitude Error function');
set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
plot(t,Psiq,'Linewidth',2)
ylabel('\boldmath$\Psi_q$','FontSize',labfont,'Interpreter','latex')
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')  

%%
% save(savename)

%%

% 
%         figure('Name','Angular Velocity')
%         h_suptitle = suptitle('QR Angular Velocity \Omega');
%         set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
%         subplot 311
%         hold on
%         plot(t,Omega(1,:),'Linewidth',2)
%         plot(t,Omegad(1,:),'r--','Linewidth',2)
%         ylabel('p [rad/s]', 'FontSize',labfont);
%         set(gca,'FontSize',afont);
%         subplot 312
%         hold on
%         plot(t,Omega(2,:),'Linewidth',2)
%         plot(t,Omegad(2,:),'r--','Linewidth',2)
%         ylabel('q [rad/s]', 'FontSize',labfont);
%         set(gca,'FontSize',afont);
%         subplot 313
%         hold on
%         plot(t,Omega(3,:),'Linewidth',2)
%         plot(t,Omegad(3,:),'r--','Linewidth',2)
%         ylabel('r [rad/s]', 'FontSize',labfont);
%         xlabel('Time [s]','FontSize',labfont)
%         hl = legend('$\Omega$','$\Omega_c$');
%         set(hl,'Interpreter','latex','FontSize',lfont);
%         set(gca,'FontSize',afont);
%      saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')         
%         
%      saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')
% 
%         
%     case 0 %Position
%         modecode = 'Position Mode';
%         figure('Name','Rotation Matrices')
%         for j=1:3
%             for n=1:3
%                 k=(j-1)*3+n;
%                 subplot(3,3,k)
%                 Rplot = reshape(R.signals.values(j,n,:),[length(R.signals.values),1]);
%                 Rcplot = reshape(Rc.signals.values(j,n,:),[length(Rc.signals.values),1]);
%                 hold on
%                 axis([0 t(end) -1.2 1.2])
%                 plot(t,Rplot,'Linewidth',2)
%                 plot(t,Rcplot,'r--','Linewidth',2)
%                 set(gca,'FontSize',afont);
%                 if k==8
%                     xlabel('Time [s]','FontSize',labfont)
%                 end
%             end
%         end
%         h_suptitle = suptitle('R and R_c \in\Re^{3\times3}');
%         set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
%         hl = legend('$R$','$R_c$');
%         set(hl,'Interpreter','latex','FontSize',lfont,'Position',[.8,.8,.1,.1]);
%     saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')
%         
%         figure('Name','Attitude Errors')
%         h_suptitle = suptitle(strcat('Attitude Errors: ',modecode));
%         set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
%         subplot 211
%         plot(t,eOmegac,'Linewidth',2);
%         ylabel('e_{\Omega}','FontSize',labfont);
%         set(gca,'FontSize',afont);
%         hl = legend('$e_p$','$e_q$','$e_r$');
%         set(hl,'Interpreter','latex','FontSize',lfont)
%         subplot 212
%         plot(t,eRc,'Linewidth',2)
%         ylabel('e_{R_c}','FontSize',labfont);
%         xlabel('Time [s]','FontSize',labfont)
%         set(gca,'FontSize',afont);
%         hl = legend('$e_{R,1}$','$e_{R,2}$','$e_{R,3}$');   
%         set(hl,'Interpreter','latex','FontSize',lfont)
%   saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')
%                             
%         figure('Name','Attitude Error Function')
%         plot(t,errorfunc,'Linewidth',2)
%         xlabel('Time [s]','FontSize',labfont)
%         ylabel('\Psi(R,R_d)','FontSize',labfont);
%         h_suptitle = suptitle('Attitude Error function');
%         set(h_suptitle,'FontSize',supfont,'Interpreter','latex');      
%         set(gca,'FontSize',afont);        
%      saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')
%         
%         figure('Name','Angular Velocity')%         
%         h_suptitle = suptitle('QR Angular Velocity \Omega');
%         set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
%         subplot 311
%         hold on
%         plot(t,Omega(1,:),'Linewidth',2)
%         plot(t,Omegac(1,:),'r--','Linewidth',2)
%         ylabel('p [rad/s]', 'FontSize',labfont);
%         set(gca,'FontSize',afont);
%         subplot 312
%         hold on
%         plot(t,Omega(2,:),'Linewidth',2)
%         plot(t,Omegac(2,:),'r--','Linewidth',2)
%         ylabel('q [rad/s]', 'FontSize',labfont);
%         set(gca,'FontSize',afont);
%         subplot 313
%         hold on
%         plot(t,Omega(3,:),'Linewidth',2)
%         plot(t,Omegac(3,:),'r--','Linewidth',2)
%         ylabel('r [rad/s]', 'FontSize',labfont);
%         xlabel('Time [s]','FontSize',labfont)
%         hl = legend('$\Omega$','$\Omega_c$');
%         set(hl,'Interpreter','latex','FontSize',lfont)
%         set(gca,'FontSize',afont);
%     saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')    
%         
%      saveas(gcf,strcat(foldername,modecode,'-',filename,num2str(nfile)),'png')
%         
% end