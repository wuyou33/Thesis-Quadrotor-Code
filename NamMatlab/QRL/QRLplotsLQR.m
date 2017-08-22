


    
    filename = 'xL';
    figure('Name',filename)
    h_sup = suptitle('Load Position $[m]$');
    set(h_sup,'FontSize',supfont,'Interpreter','latex');
    
    if casename ~= 'C'
        %     subplot(3,3,1:3)
        %     h1=plot(t,posL(1,:),'-k',t,lqrposL(1,:),'r-.','Linewidth',3);
        % ylabel('\boldmath$x$','FontSize',labfont,'Interpreter','latex')
        % set(gca,'FontSize',afont);
        %     subplot(3,3,4:6)
        subplot 211
        h1=plot(t,posL(2,:),'-k',t,lqrposL(2,:),'r-.','Linewidth',3);
        grid on
        ylabel('\boldmath$y$','FontSize',labfont,'Interpreter','latex')
        set(gca,'FontSize',afont);
        %     subplot(3,3,7:9)
        subplot 212
        plot(t,posL(3,:),'-k',t,lqrposL(3,:),'r-.','Linewidth',3)
        grid on
        ylabel('\boldmath$z$','FontSize',labfont,'Interpreter','latex')
        xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
        set(gca,'FontSize',afont);
        %     hL = subplot(3,3,2);
        %     poshL = get(hL,'position');
        %     hl = legend(hL,[h1],'\boldmath$NGC$','\boldmath$LQR$');
        %     set(hl,'position',poshL,'Interpreter','latex','FontSize',supfont);
    elseif casename == 'C'
        subplot 311
        % h1=plot(t,xLd(1,:),'o',t,posL(1,:),'-k',t,lqrposL(1,:),'r-.','Linewidth',2);
        h1=plot(t,posL(1,:),'-k',t,lqrposL(1,:),'r-.','Linewidth',3);
        grid on
        ylabel('\boldmath$x$','FontSize',labfont,'Interpreter','latex')
        set(gca,'FontSize',afont);
        subplot 312
        % plot(t,xLd(2,:),'o',t,posL(2,:),'-k',t,lqrposL(2,:),'r-.','Linewidth',2)
        plot(t,posL(2,:),'-k',t,lqrposL(2,:),'r-.','Linewidth',3)
        grid on
        ylabel('\boldmath$y$','FontSize',labfont,'Interpreter','latex')
        set(gca,'FontSize',afont);
        subplot 313
        % plot(t,xLd(3,:),'o',t,posL(3,:),'-k',t,lqrposL(3,:),'r-.','Linewidth',2)
        grid on
        plot(t,posL(3,:),'-k',t,lqrposL(3,:),'r-.','Linewidth',3)
        ylabel('\boldmath$z$','FontSize',labfont,'Interpreter','latex')
        xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
        set(gca,'FontSize',afont);
        %     hL = subplot(4,3,2);
        % hl = legend(hL,[h1],'\boldmath$x_{L,d}$','\boldmath$x_{L} NGC$','\boldmath$x_{L} LQR$');
        %     poshL = get(hL,'position');
        %     hl = legend(hL,[h1],'\boldmath$NGC$','\boldmath$LQR$');
        %     set(hl,'position',poshL,'Interpreter','latex','FontSize',lfont);
    end
    % axis(hL,'off')
    saveas(gcf,strcat(foldername,'LQR','-',filename,num2str(nfile)),'png')
    
    
    
%     %%
%     filename = 'xQlqr';
%     figure('Name',filename)
%     h_sup = suptitle('Quadrotor Position $[m]$');
%     set(h_sup,'FontSize',supfont,'Interpreter','latex');
%     
%     if casename ~= 'C'
%         subplot 211
%         h1=plot(t,lqrposQ(2,:),t,lqrposQd(2,:),'r--','Linewidth',3);
%         grid on
%         ylabel('\boldmath$y$','FontSize',labfont,'Interpreter','latex')
%         hl = legend('\boldmath$x_L$','\boldmath$x_{L,d}$');
%         set(gca,'FontSize',afont);
%         subplot 212
%         plot(t,lqrposQ(3,:),t,lqrposQd(3,:),'r--','Linewidth',3)
%         grid on
%         ylabel('\boldmath$z$','FontSize',labfont,'Interpreter','latex')
%         xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
%         set(gca,'FontSize',afont);
%     elseif casename == 'C'
%         subplot 311
%         h1=plot(t,lqrposQ(1,:),t,lqrposQd(1,:),'r--','Linewidth',3);
%         grid on
%         hl = legend('\boldmath$x_L$','\boldmath$x_{L,d}$');
%         ylabel('\boldmath$x$','FontSize',labfont,'Interpreter','latex')
%         set(gca,'FontSize',afont);
%         subplot 312
%         plot(t,lqrposQ(2,:),t,lqrposQd(2,:),'r--','Linewidth',3)
%         ylabel('\boldmath$y$','FontSize',labfont,'Interpreter','latex')
%         set(gca,'FontSize',afont);
%         subplot 313
% 
%         plot(t,lqrposQ(3,:),t,lqrposQd(3,:),'r--','Linewidth',3)
%         grid on
%         ylabel('\boldmath$z$','FontSize',labfont,'Interpreter','latex')
%         xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
%         set(gca,'FontSize',afont);
%     end
%     set(hl,'Interpreter','latex','FontSize',lfont);
%     saveas(gcf,strcat(foldername,'LQR','-',filename,num2str(nfile)),'png')
    
%     filename = 'xLlqr';
%     figure('Name',filename)
%     h_sup = suptitle('Load Position $[m]$');
%     set(h_sup,'FontSize',supfont,'Interpreter','latex');
%     
%     if casename ~= 'C'
%         subplot 211
%         h1=plot(t,lqrposL(2,:),t,xLd(2,:),'r--','Linewidth',3);
%         grid on
%         ylabel('\boldmath$y$','FontSize',labfont,'Interpreter','latex')
%         hl = legend('\boldmath$x_L$','\boldmath$x_{L,d}$');
%         set(gca,'FontSize',afont);
%         subplot 212
%         plot(t,lqrposL(3,:),t,xLd(3,:),'r--','Linewidth',3)
%         grid on
%         ylabel('\boldmath$z$','FontSize',labfont,'Interpreter','latex')
%         xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
%         set(gca,'FontSize',afont);
%     elseif casename == 'C'
%         subplot 311
%         h1=plot(t,lqrposL(1,:),t,xLd(1,:),'r--','Linewidth',3);
%         grid on
%         hl = legend('\boldmath$x_L$','\boldmath$x_{L,d}$');
%         ylabel('\boldmath$x$','FontSize',labfont,'Interpreter','latex')
%         set(gca,'FontSize',afont);
%         subplot 312
%         plot(t,lqrposL(2,:),t,xLd(2,:),'r--','Linewidth',3)
%         grid on
%         ylabel('\boldmath$y$','FontSize',labfont,'Interpreter','latex')
%         set(gca,'FontSize',afont);
%         subplot 313
% 
%         plot(t,lqrposL(3,:),t,xLd(3,:),'r--','Linewidth',3)
%         grid on
%         ylabel('\boldmath$z$','FontSize',labfont,'Interpreter','latex')
%         xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
%         set(gca,'FontSize',afont);
%     end
%     set(hl,'Interpreter','latex','FontSize',lfont);
%     saveas(gcf,strcat(foldername,'LQR','-',filename,num2str(nfile)),'png')



filename = 'QRang';
figure('Name',filename)
h_sup = suptitle('QR Angle [deg]');
set(h_sup,'FontSize',supfont,'Interpreter','latex');
if casename ~= 'A'
    if casename ~= 'B'
        subplot 211
    end
    plot(t,angleQ(:,1),'-k',t,lqrangleQ(:,1),'r-.','Linewidth',3)
    grid on
    ylabel('\boldmath$\phi$','FontSize',labfont,'Interpreter','latex')
    set(gca,'FontSize',afont);
    if casename ~= 'B'
        subplot 212
        plot(t,angleQ(:,2),'-k',t,lqrangleQ(:,2),'r-.','Linewidth',3)
        grid on
        set(gca,'FontSize',afont);
        ylabel('\boldmath$\theta$','FontSize',labfont,'Interpreter','latex')
%         subplot 313
%         plot(t,lqrangleQ(:,2),'r-.','Linewidth',3)
%         grid on
%         set(gca,'FontSize',afont);
%         ylabel('\boldmath$\theta$','FontSize',labfont,'Interpreter','latex')
    end
elseif casename == 'A'
    subplot 211
    plot(t,angleQ(:,1),'-k','Linewidth',3)
    grid on
    ylabel('\boldmath$\phi$','FontSize',labfont,'Interpreter','latex')
    set(gca,'FontSize',afont);
    subplot 212
    plot(t,lqrangleQ(:,1),'r-.','Linewidth',3)
    grid on
    set(gca,'FontSize',afont);
    ylabel('\boldmath$\phi$','FontSize',labfont,'Interpreter','latex')
else
    disp('cannot generate QR ang plot')
end
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
saveas(gcf,strcat(foldername,'LQR','-',filename,num2str(nfile)),'png')


filename = 'Lang';
figure('Name',filename)
h_sup = suptitle('Load Angle [deg]');
set(h_sup,'FontSize',supfont,'Interpreter','latex');
if casename == 'C'
    subplot 211
end
plot(t,angleL(:,1),'-k',t,lqrangleL(:,1),'r-.','Linewidth',3)
grid on
% hl = legend('\boldmath$NGC$','\boldmath$LQR$');
ylabel('\boldmath$\phi_L$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
% set(hl,'Interpreter','latex','FontSize',lfont);
if casename == 'C'
    subplot 212
    plot(t,angleL(:,2),'-k',t,lqrangleL(:,2),'r-.','Linewidth',3)
    grid on
    ylabel('\boldmath$e_y$','FontSize',labfont,'Interpreter','latex')
    set(gca,'FontSize',afont);
    ylabel('\boldmath$\theta_L$','FontSize',labfont,'Interpreter','latex')
end
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
saveas(gcf,strcat(foldername,'LQR','-',filename,num2str(nfile)),'png')

filename = 'exL';
figure('Name',filename)
h_suptitle = suptitle('Load Position Error $[m]$');
set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
if casename ~= 'C'
    subplot 211
    plot(t,exL(2,:),'-k',t,lqrexL(2,:),'r-.','Linewidth',3)
    grid on
    ylabel('\boldmath$e_y$','FontSize',labfont,'Interpreter','latex')
    set(gca,'FontSize',afont);
    subplot 212
    plot(t,exL(3,:),'-k',t,lqrexL(3,:),'r-.','Linewidth',3)
    grid on
    ylabel('\boldmath$e_z$','FontSize',labfont,'Interpreter','latex')
elseif casename == 'C'
    subplot 311
    plot(t,exL(1,:),'-k',t,lqrexL(1,:),'r-.','Linewidth',3)
    grid on
    % hl = legend('\boldmath$NGC$','\boldmath$LQR$');
    ylabel('\boldmath$e_x$','FontSize',labfont,'Interpreter','latex')
    set(gca,'FontSize',afont);
    % set(hl,'Interpreter','latex','FontSize',lfont);
    subplot 312
    plot(t,exL(2,:),'-k',t,lqrexL(2,:),'r-.','Linewidth',3)
    grid on
    ylabel('\boldmath$e_y$','FontSize',labfont,'Interpreter','latex')
    set(gca,'FontSize',afont);
    subplot 313
    plot(t,exL(3,:),'-k',t,lqrexL(3,:),'r-.','Linewidth',3)
    grid on
    ylabel('\boldmath$e_z$','FontSize',labfont,'Interpreter','latex')
end
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
saveas(gcf,strcat(foldername,'LQR','-',filename,num2str(nfile)),'png')

%%
filename = 'exQ';
figure('Name',filename)
h_suptitle = suptitle('QR Position Error $[m]$');
set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
if casename ~= 'C'
    subplot 211
    plot(t,exQ(2,:),'r-.','Linewidth',3)
    grid on
    ylabel('\boldmath$e_y$','FontSize',labfont,'Interpreter','latex')
    set(gca,'FontSize',afont);
    subplot 212
    plot(t,exQ(3,:),'r-.','Linewidth',3)
    grid on
    ylabel('\boldmath$e_z$','FontSize',labfont,'Interpreter','latex')
elseif casename == 'C'
    subplot 311
    plot(t,exQ(1,:),'r-.','Linewidth',3)
    grid on
    % hl = legend('\boldmath$NGC$','\boldmath$LQR$');
    ylabel('\boldmath$e_x$','FontSize',labfont,'Interpreter','latex')
    set(gca,'FontSize',afont);
    % set(hl,'Interpreter','latex','FontSize',lfont);
    subplot 312
    plot(t,exQ(2,:),'r-.','Linewidth',3)
    grid on
    ylabel('\boldmath$e_y$','FontSize',labfont,'Interpreter','latex')
    set(gca,'FontSize',afont);
    subplot 313
    plot(t,exQ(3,:),'r-.','Linewidth',3)
    grid on
    ylabel('\boldmath$e_z$','FontSize',labfont,'Interpreter','latex')
end
xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
set(gca,'FontSize',afont);
saveas(gcf,strcat(foldername,'LQR','-',filename,num2str(nfile)),'png')

%%
if casename == 'A'

    
    % exLperc=exLperc(~isinf(exLperc));
    % lqrexLperc=lqrexLperc(~isinf(lqrexLperc));
    
    filename = 'exL_xLd';
    figure('Name',filename)
    h_suptitle = suptitle('${\parallel e_x\parallel} \>\;/x_{L,d}\;[\%]$');
    set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
    if casename == 'C'
        subplot 311
        plot(t,exLperc(1,:),'-k',t,lqrexLperc(1,:),'r-.','Linewidth',3)
        grid on
        hl = legend('\boldmath$NGC$','\boldmath$LQR$');
        ylabel('\boldmath$x$','FontSize',labfont,'Interpreter','latex')
        axis([0 t(end) 0 110])
        set(gca,'FontSize',afont);
        set(hl,'Interpreter','latex','FontSize',lfont);
        subplot 312
    end
    plot(t,exLperc(2,:),'-k',t,lqrexLperc(2,:),'r-.','Linewidth',3)
    grid on
    ylabel('\boldmath$y$','FontSize',labfont,'Interpreter','latex')
    axis([0 t(end) 0 110])
    set(gca,'FontSize',afont);
    if casename == 'C'
        subplot 313
        plot(t,exLperc(3,:),'-k',t,lqrexLperc(3,:),'r-.','Linewidth',3)
        grid on
        ylabel('\boldmath$z$','FontSize',labfont,'Interpreter','latex')
        axis([0 t(end) 0 110])
    end
    xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
    set(gca,'FontSize',afont);
    saveas(gcf,strcat(foldername,'LQR','-',filename,num2str(nfile)),'png')
end


%
% %%
%     lfont = 18; %Legend Fontsize
%     afont = 16; %Axis Fontsize
%     labfont = 20; %Label Fontsize
%     supfont = 25; %Suptitle Fontsize

%     foldername = 'C:\Users\Nam\Documents\Git\Thesis-Quadrotor-Code\NamMatlab\QRL\MatlabImages\';

% for nfile = 18:100

%     savename = strcat(foldername,'LQR',num2str(nfile),'.mat');
%     if exist(savename,'file') == 0
%         break
%     end

%     savename = strcat(foldername,'GainsLQR',num2str(nfile),'.mat');
%     if exist(savename,'file') == 0
%         save(savename,'comment','facR','kR','kOmega','facq','kq','komega',...
%             'facx','kpx','kdx','omega_n1_xL','omega_n2_xL','omega_n1_q',...
%             'omega_n2_q','omega_n1_R','omega_n2_R','omega_n1_CFP','omega_n2_CFP','zeta_xL','zeta_q',...
%             'zeta_R','LQRA','LQRB','LQRC','LQRD','K','LQRQ','LQRR')
% %         save(savename,'comment','LQRA','LQRB','LQRC','LQRD','K','LQRQ','LQRR')
%
%         break
%     end
% end

% save(strcat(foldername,num2str(nfile),comment,'.mat'))



%% Inputs

% filename = 'f';
% figure('Name',filename)
% h_suptitle = suptitle(strcat(filename,' $[N]$'));
% set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
% subplot(6,1,[1,2])
% plot(t,f,'Linewidth',2)
% ylabel('\boldmath$f_{total}$','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% subplot 613
% plot(t,fi(1,:),'Linewidth',2)
% ylabel('\boldmath$f_1$','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% subplot 614
% plot(t,fi(2,:),'Linewidth',2)
% ylabel('\boldmath$f_2$','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% subplot 615
% plot(t,fi(3,:),'Linewidth',2)
% ylabel('\boldmath$f_3$','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% subplot 616
% plot(t,fi(4,:),'Linewidth',2)
% ylabel('\boldmath$f_4$','FontSize',labfont,'Interpreter','latex')
% xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% saveas(gcf,strcat(foldername,'LQR','-',filename,num2str(nfile)),'png')
%
% filename = 'M';
% figure('Name',filename)
% h_suptitle = suptitle(strcat(filename,' $[Nm]$'));
% set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
% plot(t,M,'Linewidth',2)
% hl = legend('\boldmath$\tau_\phi$','\boldmath$\tau_\theta$','\boldmath$\tau_\psi$');
% set(hl,'Interpreter','latex','FontSize',lfont)
% ylabel('\boldmath$M$','FontSize',labfont,'Interpreter','latex')
% xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% saveas(gcf,strcat(foldername,'LQR','-',filename,num2str(nfile)),'png')

%%
% filename = 'Lpos';
% figure('Name',filename)
% h_sup = suptitle('Load Pos./Vel./Acc.');
% set(h_sup,'FontSize',supfont,'Interpreter','latex');
% subplot 311
% plot(t,posL,t,lqrposL,'Linewidth',2)
% hl = legend('\boldmath$x$','\boldmath$y$','\boldmath$z$');
% set(hl,'Interpreter','latex','FontSize',lfont);
% ylabel('\boldmath$[m]$','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% subplot 312
% plot(t,velL,'Linewidth',2)
% hl = legend('\boldmath$\dot{x}$','\boldmath$\dot{y}$','\boldmath$\dot{z}$');
% set(hl,'Interpreter','latex','FontSize',lfont);
% ylabel('\boldmath$[m/s]$','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% subplot 313
% plot(t,accL,'Linewidth',2)
% hl = legend('\boldmath$\ddot{x}$','\boldmath$\ddot{y}$','\boldmath$\ddot{z}$');
% set(hl,'Interpreter','latex','FontSize',lfont);
% ylabel('\boldmath$[m/s^2]$','FontSize',labfont,'Interpreter','latex')
% xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% hLPosOverview = gcf;
% saveas(gcf,strcat(foldername,'LQR','-',filename,num2str(nfile)),'png')

% filename = 'QRpos';
% figure('Name',filename)
% h_sup = suptitle('QR Pos./Vel./Acc.');
% set(h_sup,'FontSize',supfont,'Interpreter','latex');
% subplot 311
% plot(t,posQ,t,lqrposQ,'Linewidth',2)
% hl = legend('\boldmath$x$','\boldmath$y$','\boldmath$z$','\boldmath$x_{LQR}$','\boldmath$y_{LQR}$','\boldmath$z_{LQR}$');
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
% saveas(gcf,strcat(foldername,'LQR','-',filename,num2str(nfile)),'png')

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
% saveas(gcf,strcat(foldername,'LQR','-',filename,num2str(nfile)),'png')

%%
% filename = 'QRang';
% figure('Name',filename)
% h_sup = suptitle('QR Angle [deg]');
% set(h_sup,'FontSize',supfont,'Interpreter','latex');
% subplot 211
% plot(t,angleQ(:,1),t,angleQ(:,2),'Linewidth',2)
% axis([0 t(end) min(min(angleQ(:,1),angleQ(:,2)))-5 max(max(angleQ(:,1),angleQ(:,2)))+5])
% hl = legend('\boldmath$\phi_{Q,GC}$','\boldmath$\theta_{Q,GC}$');
% ylabel('GC','FontSize',labfont,'Interpreter','latex')
% set(hl,'Interpreter','latex','FontSize',lfont);
% set(gca,'color','none','FontSize',afont)
% set(gca,'FontSize',afont);
% subplot 212
% % plot(t,angleQ(:,3),t,lqrangleQ(:,3),'Linewidth',2)
% % hl = legend('\boldmath$\psi_Q$','\boldmath$\psi_{Q,LQR}$');
% plot(t,lqrangleQ(:,1),t,lqrangleQ(:,2),'Linewidth',2)
% axis([0 t(end) min(min(lqrangleQ(:,1),lqrangleQ(:,2)))-5 max(max(lqrangleQ(:,1),lqrangleQ(:,2)))+5])
% hl = legend('\boldmath$\phi_{Q,LQR}$','\boldmath$\theta_{Q,LQR}$');
% ylabel('LQR','FontSize',labfont,'Interpreter','latex')
% set(hl,'Interpreter','latex','FontSize',lfont);
% set(gca,'color','none','FontSize',afont)
% set(gca,'FontSize',afont);
% % ylabel('\boldmath$[^\circ]$','FontSize',labfont,'Interpreter','latex')
% % set(hl,'Interpreter','latex','FontSize',lfont);
% % set(gca,'color','none','FontSize',afont)
% xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% saveas(gcf,strcat(foldername,'LQR','-',filename,num2str(nfile)),'png')

% filename = 'QRvel';
% figure('Name',filename)
% h_sup = suptitle('QR $\Omega$/$\dot{\Omega}$');
% set(h_sup,'FontSize',supfont,'Interpreter','latex');
% subplot 211
% plot(t,OmegaQ,'Linewidth',2)
% hl = legend('\boldmath$p_Q$','\boldmath$q_Q$','\boldmath$r_Q$');
% set(hl,'Interpreter','latex','FontSize',lfont);
% ylabel('\boldmath$[^\circ/s]$','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% subplot 212
% plot(t,dOmegaQ,'Linewidth',2)
% hl = legend('\boldmath$\dot{p}_Q$','\boldmath$\dot{q}_Q$','\boldmath$\dot{r}_Q$');
% set(hl,'Interpreter','latex','FontSize',lfont);
% ylabel('\boldmath$[^\circ/s^2]$','FontSize',labfont,'Interpreter','latex')
% xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% saveas(gcf,strcat(foldername,'LQR','-',filename,num2str(nfile)),'png')

% filename = 'Lang';
% figure('Name',filename)
% h_sup = suptitle('Load Angle [deg]');
% set(h_sup,'FontSize',supfont,'Interpreter','latex');
% subplot 211
% % plot(t,angleL,'Linewidth',2)
% % hl = legend('\boldmath$\phi_L$','\boldmath$\theta_L$','\boldmath$\psi_L$');
% plot(t,angleL(:,1),t,angleL(:,2),'Linewidth',2)
% hl = legend('\boldmath$\phi_{L,GC}$','\boldmath$\theta_{L,GC}$');
% ylabel('GC','FontSize',labfont,'Interpreter','latex')
% set(hl,'Interpreter','latex','FontSize',lfont);
% set(gca,'color','none','FontSize',afont)
% subplot 212
% % plot(t,OmegaL,'Linewidth',2)
% % hl = legend('\boldmath$p_L$','\boldmath$q_L$','\boldmath$r_L$');
% % plot(t,OmegaL(:,1),t,OmegaL(:,2),'Linewidth',2)
% plot(t,lqrangleL(:,1),t,lqrangleL(:,2),'Linewidth',2)
% hl = legend('\boldmath$\phi_{L,LQR}$','\boldmath$\theta_{L,LQR}$');
% set(hl,'Interpreter','latex','FontSize',lfont);
% ylabel('LQR','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% % subplot 313
% % plot(t,dOmegaL,'Linewidth',2)
% % hl = legend('$\dot{p}_L$','$\dot{q}_L$','$\dot{r}_L$');
% % set(hl,'Interpreter','latex','FontSize',lfont);
% % ylabel('\boldmath$acc [^\circ/s^2]$','FontSize',labfont,'Interpreter','latex')
% % xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
% saveas(gcf,strcat(foldername,'LQR','-',filename,num2str(nfile)),'png')

% figure
% plot(t,pos,'Linewidth',2)
% h_suptitle = suptitle('QR Position');
% set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
% hl = legend('$x$','$y$','$z$');
% set(hl,'Interpreter','latex','FontSize',lfont)

%% Rotation Matrix

% filename = 'Rotations';
% figure('Name',filename)
% h_sup = suptitle('Rotation $R\in\Re^{3\times3}$');
% set(h_sup,'FontSize',supfont,'Interpreter','latex');
% for j=1:3
%     for n=1:3
%         k=(j-1)*3+n;
%         subplot(3,3,k)
%         Rplot = reshape(simoutR.signals.values(j,n,:),[length(simoutR.signals.values),1]);
%         Rcplot = reshape(simoutRc.signals.values(j,n,:),[length(simoutRc.signals.values),1]);
%         hold on
%         axis([0 t(end) -1.1 1.1])
% %         axis([0 4 -1.2 1.2])
%         plot(t,Rplot,'Linewidth',2)
%         plot(t,Rcplot,'r-.','Linewidth',2)
%         set(gca,'FontSize',afont);
%         if k==8
%             xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
%         end
%     end
% end
% switch mode
%     case 2 % QRL Attitude Controlled Mode
%         hl = legend('\boldmath$R$','\boldmath$R_d$');
%     otherwise
%         hl = legend('\boldmath$R$','\boldmath$R_c$');
% end
% set(hl,'Interpreter','latex','FontSize',lfont,'Position',[.8,.8,.1,.1]);
% saveas(gcf,strcat(foldername,'LQR','-',filename,num2str(nfile)),'png')

%% q

% filename = 'q';
% figure('Name',filename)
% h_suptitle = suptitle('Unit vector $q$ from QR to Load');
% set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
% plot(t,q,'LineWidth',2)
%
% % hl = legend('$\vec{q}\cdot\vec{b}_1$','$\vec{q}\cdot\vec{b}_2$','$\vec{q}\cdot\vec{b}_3$');
% switch mode
%     case 3 % QRL Load Attitude Controlled Mode
%         subplot 311
%         plot(t,q(1,:),t,qcplot(1,:),'r-.','Linewidth',2)
%         ylabel('\boldmath$\vec{q}\cdot\vec{b}_1$','FontSize',labfont,'Interpreter','latex')
%         set(gca,'FontSize',afont);
%         subplot 312
%         plot(t,q(2,:),t,qcplot(2,:),'r-.','Linewidth',2)
%         ylabel('\boldmath$\vec{q}\cdot\vec{b}_2$','FontSize',labfont,'Interpreter','latex')
%         set(gca,'FontSize',afont);
%         subplot 313
%         plot(t,q(3,:),t,qcplot(3,:),'r-.','Linewidth',2)
%         ylabel('\boldmath$\vec{q}\cdot\vec{b}_3$','FontSize',labfont,'Interpreter','latex')
%         set(gca,'FontSize',afont);
%         hl = legend('\boldmath$\vec{q}$','\boldmath$\vec{q}_d$');
%     case 4 % QRL Load Position Controlled Mode
%         subplot 311
%         plot(t,q(1,:),t,qcplot(1,:),'r-.','Linewidth',2)
%         ylabel('\boldmath$\vec{q}\cdot\vec{b}_1$','FontSize',labfont,'Interpreter','latex')
%         set(gca,'FontSize',afont);
%         subplot 312
%         plot(t,q(2,:),t,qcplot(2,:),'r-.','Linewidth',2)
%         ylabel('\boldmath$\vec{q}\cdot\vec{b}_2$','FontSize',labfont,'Interpreter','latex')
%         set(gca,'FontSize',afont);
%         subplot 313
%         plot(t,q(3,:),t,qcplot(3,:),'r-.','Linewidth',2)
%         ylabel('\boldmath$\vec{q}\cdot\vec{b}_3$','FontSize',labfont,'Interpreter','latex')
%         set(gca,'FontSize',afont);
%         hl = legend('\boldmath$\vec{q}$','\boldmath$\vec{q}_c$');
% end
% set(hl,'Interpreter','latex','FontSize',lfont,'Position',[.8,.8,.1,.1]);
% xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex');
% saveas(gcf,strcat(foldername,'LQR','-',filename,num2str(nfile)),'png')

%% qplots
%
% filename = 'qplots';
% figure('Name',filename)
% h_suptitle = suptitle('Unit vector $q$ from QR to Load');
% set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
% plot(t,q,'LineWidth',2)
% subplot 311
% plot(t,q,'LineWidth',2)
% ylabel('\boldmath$q$','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% subplot 312
% plot(t,dq,'LineWidth',2)
% ylabel('\boldmath$\dot{q}$','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% subplot 313
% plot(t,ddq,'LineWidth',2)
% ylabel('\boldmath$\ddot{q}$','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% hl = legend('\boldmath$\vec{b}_1$','\boldmath$\vec{b}_2$','\boldmath$\vec{b}_3$');
%
% set(hl,'Interpreter','latex','FontSize',lfont,'Position',[.8,.8,.1,.1]);
% xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex');
% saveas(gcf,strcat(foldername,'LQR','-',filename,num2str(nfile)),'png')

%% Errors

% filename = 'eR';
% figure('Name',filename)
% h_suptitle = suptitle('QR Attitude Error $\in TSO(3)$');
% set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
% subplot 211
% plot(t,eR,'Linewidth',2)
% ylabel('\boldmath$e_{R}$','FontSize',labfont,'Interpreter','latex');
% set(gca,'FontSize',afont);
% hl = legend('\boldmath$e_{R,1}$','\boldmath$e_{R,2}$','\boldmath$e_{R,3}$','FontSize',lfont);
% set(hl,'Interpreter','latex','FontSize',lfont);
% subplot 212
% plot(t,eOmega,'Linewidth',2);
% ylabel('\boldmath$e_{\Omega}$','FontSize',labfont,'Interpreter','latex');
% set(gca,'FontSize',afont);
% hl = legend('\boldmath$e_{\Omega,1}$','\boldmath$e_{\Omega,2}$','\boldmath$e_{\Omega,3}$','FontSize',lfont);
% set(hl,'Interpreter','latex','FontSize',lfont);
% xlabel('Time [s]','FontSize',labfont,'Interpreter','latex')
% saveas(gcf,strcat(foldername,'LQR','-',filename,num2str(nfile)),'png')

% filename = 'eq';
% figure('Name',filename)
% h_suptitle = suptitle('Load Attitude Error $\in TS^2$');
% set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
% subplot 211
% plot(t,eq,'Linewidth',2);
% ylabel('\boldmath$e_{q}$','FontSize',labfont,'Interpreter','latex');
% set(gca,'FontSize',afont);
% hl = legend('\boldmath$e_{q,1}$','\boldmath$e_{q,2}$','\boldmath$e_{q,3}$','FontSize',lfont);
% set(hl,'Interpreter','latex','FontSize',lfont);
% subplot 212
% plot(t,edq,'Linewidth',2)
% ylabel('\boldmath$e_{\dot{q}}$','FontSize',labfont,'Interpreter','latex');
% xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% hl = legend('\boldmath$e_{\dot{q},1}$','\boldmath$e_{\dot{q},2}$','\boldmath$e_{\dot{q},3}$','FontSize',lfont);
% set(hl,'Interpreter','latex','FontSize',lfont);
% saveas(gcf,strcat(foldername,'LQR','-',filename,num2str(nfile)),'png')
%
% filename = 'exL';
% figure('Name',filename)
% h_suptitle = suptitle('Load Position Error $[m]$');
% set(h_suptitle,'FontSize',supfont,'Interpreter','latex');
% subplot 211
% plot(t,exL,'Linewidth',2)
% hl = legend('\boldmath$e_{x_{L,GC}}$','\boldmath$e_{y_{L,GC}}$','\boldmath$e_{z_{L,GC}}$');
% ylabel('\boldmath$e_{x_L}$,GC','FontSize',labfont,'Interpreter','latex')
% % xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% set(hl,'Interpreter','latex','FontSize',lfont);
% subplot 212
% plot(t,lqrexL,'Linewidth',2)
% hl = legend('\boldmath$e_{x_{L,LQR}}$','\boldmath$e_{y_{L,LQR}}$','\boldmath$e_{z_{L,LQR}}$');
% ylabel('\boldmath$e_{x_L}$,LQR','FontSize',labfont,'Interpreter','latex')
% xlabel('\boldmath$Time [s]$','FontSize',labfont,'Interpreter','latex')
% set(gca,'FontSize',afont);
% set(hl,'Interpreter','latex','FontSize',lfont);
% saveas(gcf,strcat(foldername,'LQR','-',filename,num2str(nfile)),'png')