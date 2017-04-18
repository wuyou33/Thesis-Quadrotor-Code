%% Inputs

filename = 'Input f';
figure('Name',filename)
h_suptitle = suptitle(strcat(filename,'[N]'));
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
saveas(gcf,strcat(foldername,modecode,'-',filename,date),'png');

filename = 'Input M';
figure('Name',filename)
h_suptitle = suptitle(filename);
set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
plot(t,M,'Linewidth',2)
hl = legend('$\tau_\phi$','$\tau_\theta$','$\tau_\psi$');
set(hl,'Interpreter','latex','FontSize',lfont)
ylabel('\boldmath$M [Nm]$','FontSize',labfont,'Interpreter','latex')
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
saveas(gcf,strcat(foldername,modecode,'-',filename,date),'png');

%%
filename = 'LPosOverview';
figure('Name',filename)
h_sup = suptitle('Load Pos./Vel./Acc.');
set(h_sup,'FontSize',supfont,'Interpreter','latex');
subplot 311
plot(t,posL,'Linewidth',2)
hl = legend('$x$','$y$','$z$');
ylabel('\boldmath$pos [m]$','FontSize',labfont,'Interpreter','latex')
set(hl,'Interpreter','latex','FontSize',lfont);
subplot 312
plot(t,velL,'Linewidth',2)
hl = legend('$\dot{x}$','$\dot{y}$','$\dot{z}$');
set(hl,'Interpreter','latex','FontSize',lfont);
ylabel('\boldmath$vel [m/s]$','FontSize',labfont,'Interpreter','latex')
subplot 313
plot(t,accL,'Linewidth',2)
hl = legend('$\ddot{x}$','$\ddot{y}$','$\ddot{z}$');
set(hl,'Interpreter','latex','FontSize',lfont);
ylabel('\boldmath$acc [m/s^2]$','FontSize',labfont,'Interpreter','latex')
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
hLPosOverview = gcf;
saveas(gcf,strcat(foldername,modecode,'-',filename,date),'png');

filename = 'QRPosOverview';
figure('Name',filename)
h_sup = suptitle('QR Pos./Vel./Acc.');
set(h_sup,'FontSize',supfont,'Interpreter','latex');
subplot 311
plot(t,posQ,'Linewidth',2)
hl = legend('$x$','$y$','$z$');
ylabel('\boldmath$pos [m]$','FontSize',labfont,'Interpreter','latex')
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(hl,'Interpreter','latex','FontSize',lfont);
% subplot 312
% plot(t,velQ,'Linewidth',2)
% hl = legend('$\dot{x}$','$\dot{y}$','$\dot{z}$');
% set(hl,'Interpreter','latex','FontSize',lfont);
% ylabel('vel [m/s]','FontSize',labfont)
% subplot 313
% plot(t,accQ,'Linewidth',2)
% hl = legend('$\ddot{x}$','$\ddot{y}$','$\ddot{z}$');
% set(hl,'Interpreter','latex','FontSize',lfont);
% ylabel('acc [m/s^2]','FontSize',labfont)
hQRPosOverview = gcf;
saveas(gcf,strcat(foldername,modecode,'-',filename,date),'png');

filename = 'QR-Load Position';
figure('Name',filename)
h_suptitle = suptitle(filename);
set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
subplot 311
hold on
plot(t,posL(1,:),t,posQ(1,:),'Linewidth',2);
% plot(t,xdes(1)*ones(size(posL(1,:))),'r--','Linewidth',2);
ylabel('\boldmath$x [m]$','FontSize',labfont,'Interpreter','latex');
set(gca,'FontSize',afont);
% h_t=ylabel('x');
% set(h_t, 'FontSize',labfont);
hl = legend('$x_L$','$x_Q$');
set(hl,'Interpreter','latex','FontSize',lfont);
subplot 312
hold on
plot(t,posL(2,:),t,posQ(2,:),'Linewidth',2);
% plot(t,xdes(2)*ones(size(posL(2,:))),'r--','Linewidth',2);
ylabel('\boldmath$y [m]$','FontSize',labfont,'Interpreter','latex');
set(gca,'FontSize',afont);
% h_t=ylabel('y');
% set(h_t, 'FontSize',labfont);
hl = legend('$y_L$','$y_Q$');
set(hl,'Interpreter','latex','FontSize',lfont,'Interpreter','latex');
subplot 313
hold on
plot(t,posL(3,:),t,posQ(3,:),'Linewidth',2);
% plot(t,xdes(3)*ones(size(posL(3,:))),'r--','Linewidth',2);
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
ylabel('\boldmath$z [m]$','FontSize',labfont,'Interpreter','latex');
set(gca,'FontSize',afont);
% h_t=ylabel('z');
% set(h_t, 'FontSize',labfont);
hl = legend('$z_L$','$z_Q$');
set(hl,'Interpreter','latex','FontSize',lfont);
saveas(gcf,strcat(foldername,modecode,'-',filename,date),'png');

%%
filename = 'QRAngOverview';
figure('Name',filename)
h_sup = suptitle('QR Angle/$\Omega$/$\dot{\Omega}$');
set(h_sup,'FontSize',supfont,'Interpreter','latex');
subplot 311
plot(t,angleQ,'Linewidth',2)
hl = legend('$\phi_Q$','$\theta_Q$','$\psi_Q$');
ylabel('\boldmath$ang [rad]$','FontSize',labfont,'Interpreter','latex')
set(hl,'Interpreter','latex','FontSize',lfont);
set(gca,'color','none')
subplot 312
plot(t,OmegaQ,'Linewidth',2)
hl = legend('$p_Q$','$q_Q$','$r_Q$');
set(hl,'Interpreter','latex','FontSize',lfont);
ylabel('\boldmath$vel [rad/s]$','FontSize',labfont,'Interpreter','latex')
subplot 313
plot(t,dOmegaQ,'Linewidth',2)
hl = legend('$\dot{p}_Q$','$\dot{q}_Q$','$\dot{r}_Q$');
set(hl,'Interpreter','latex','FontSize',lfont);
ylabel('\boldmath$acc [rad/s^2]$','FontSize',labfont,'Interpreter','latex')
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
hQRAngOverview = gcf;
saveas(gcf,strcat(foldername,modecode,'-',filename,date),'png');

filename = 'LAngOverview';
figure('Name',filename)
h_sup = suptitle('Load Angle/$\Omega$/$\dot{\Omega}$');
set(h_sup,'FontSize',supfont,'Interpreter','latex');
subplot 311
plot(t,angleL,'Linewidth',2)
hl = legend('$\phi_L$','$\theta_L$','$\psi_L$');
ylabel('\boldmath$ang [rad]$','FontSize',labfont,'Interpreter','latex')
set(hl,'Interpreter','latex','FontSize',lfont);
set(gca,'color','none')
subplot 312
plot(t,OmegaL,'Linewidth',2)
hl = legend('$p_L$','$q_L$','$r_L$');
set(hl,'Interpreter','latex','FontSize',lfont);
ylabel('\boldmath$vel [rad/s]$','FontSize',labfont,'Interpreter','latex')
subplot 313
plot(t,dOmegaL,'Linewidth',2)
hl = legend('$\dot{p}_L$','$\dot{q}_L$','$\dot{r}_L$');
set(hl,'Interpreter','latex','FontSize',lfont);
ylabel('\boldmath$acc [rad/s^2]$','FontSize',labfont,'Interpreter','latex')
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
hLAngOverview = gcf;
saveas(gcf,strcat(foldername,modecode,'-',filename,date),'png');

% figure
% plot(t,pos,'Linewidth',2)
% h_suptitle = suptitle('QR Position');
% set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
% hl = legend('$x$','$y$','$z$');
% set(hl,'Interpreter','latex','FontSize',lfont)

%% Rotation Matrix

filename = 'Rotation Matrix';
figure('Name',filename)
h_sup = suptitle(filename);
set(h_sup,'FontSize',supfont,'Interpreter','latex');
for j=1:3
    for n=1:3
        k=(j-1)*3+n;
        subplot(3,3,k)
        Rplot = reshape(R.signals.values(j,n,:),[length(R.signals.values),1]);
        Rcplot = reshape(Rc.signals.values(j,n,:),[length(Rc.signals.values),1]);
        hold on
        axis([0 t(end) -1.2 1.2])
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
        hl = legend('$R$','$R_d$');
    otherwise
        hl = legend('$R$','$R_c$');
end
set(hl,'Interpreter','latex','FontSize',lfont,'Position',[.8,.8,.1,.1]);
saveas(gcf,strcat(foldername,modecode,'-',filename,date),'png');

%% q

filename = 'q';
figure('Name',filename)
h_suptitle = suptitle('Unit vector $q$ from QR to Load');
set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
plot(t,q,'LineWidth',2)

hl = legend('$\vec{q}\cdot\vec{b}_1$','$\vec{q}\cdot\vec{b}_2$','$\vec{q}\cdot\vec{b}_3$');
qcplot = reshape(simoutqc.signals.values,[3,length(simoutqc.signals.values)]);
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
saveas(gcf,strcat(foldername,modecode,'-',filename,date),'png');

%% Errors

filename = 'QR Attitude Error';
figure('Name',filename)
h_suptitle = suptitle(strcat(filename,' $\in TSO(3)$'));
set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
subplot 211
plot(t,eOmega,'Linewidth',2);
ylabel('\boldmath$e_{\Omega}$','FontSize',labfont,'Interpreter','latex');
set(gca,'FontSize',afont);
hl = legend('$e_{\Omega,1}$','$e_{\Omega,2}$','$e_{\Omega,3}$','FontSize',lfont);
set(hl,'Interpreter','latex','FontSize',lfont);
subplot 212
plot(t,eR,'Linewidth',2)
ylabel('\boldmath$e_{R}$','FontSize',labfont,'Interpreter','latex');
xlabel('Time [s]','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
hl = legend('$e_{R,1}$','$e_{R,2}$','$e_{R,3}$','FontSize',lfont);
set(hl,'Interpreter','latex','FontSize',lfont);
saveas(gcf,strcat(foldername,modecode,'-',filename,date),'png');

filename = 'Load Attitude Error';
figure('Name',filename)
h_suptitle = suptitle(strcat(filename,' $\in TS^2$'));
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
saveas(gcf,strcat(foldername,modecode,'-',filename,date),'png');

%%
savename = strcat(foldername,modecode,'-',date,'.mat');
save(savename)

%%

% 
%         figure('Name','Attitude Error Function')
%         plot(t,errorfunc,'Linewidth',2)
%         xlabel('Time [s]','FontSize',labfont)
%         ylabel('\Psi(R,R_d)','FontSize',labfont);
%         h_suptitle = suptitle('Attitude Error function');
%         set(h_suptitle,'FontSize',supfont,'Interpreter','latex');      
%         set(gca,'FontSize',afont);        
%         saveas(gcf,strcat(foldername,date,'AttitudeErrorFunction1'),'png');        
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
%         saveas(gcf,strcat(foldername,date,'AngularVelocity1'),'png');           
%         
%         saveas(hQRPosOverview,strcat(foldername,date,'PosVelAccOverview1'),'png');
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
%         saveas(gcf,strcat(foldername,date,'RotationMatrix0'),'png');
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
%         saveas(gcf,strcat(foldername,date,'AttitudeErrors0'),'png');
%                             
%         figure('Name','Attitude Error Function')
%         plot(t,errorfunc,'Linewidth',2)
%         xlabel('Time [s]','FontSize',labfont)
%         ylabel('\Psi(R,R_d)','FontSize',labfont);
%         h_suptitle = suptitle('Attitude Error function');
%         set(h_suptitle,'FontSize',supfont,'Interpreter','latex');      
%         set(gca,'FontSize',afont);        
%         saveas(gcf,strcat(foldername,date,'AttitudeErrorFunction0'),'png');
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
%         saveas(gcf,strcat(foldername,date,'AngularVelocity0'),'png');      
%         
%         saveas(hQRPosOverview,strcat(foldername,date,'PosVelAccOverview0'),'png');
%         
% end