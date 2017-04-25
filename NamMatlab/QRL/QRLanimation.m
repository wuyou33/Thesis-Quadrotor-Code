pausefactor = 1;

POSL = posL;
XL = POSL(1,:);
YL = POSL(2,:);
ZL = POSL(3,:);

POSQR = posQ;
XQR = POSQR(1,:);
YQR = POSQR(2,:);
ZQR = POSQR(3,:);

%%
tend = t(end);
ts = tend/length(t);
% xmin = min(min(XL,XQR))-0.5;
% ymin = min(min(YL,YQR))-0.5;
% zmin = min(min(ZL,ZQR))-1;
% xmax = max(max(XL,XQR))+0.5;
% ymax = max(max(YL,YQR))+0.5;
% zmax = max(max(ZL,ZQR))+1;
zmin = -5;
zmax = 5;
ymin = -1;
ymax = 9;
xmin = -2;
xmax = 2;

% I Frame 
Ix = [0.1;0;0];
Iy = [0;0.1;0];
Iz = [0;0;0.1];
Iframe = [Ix Iy Iz];

% Bframe initial
Blength = 0.6;
Bframe = R.signals.values(:,:,1);
Bx = [XQR(1); YQR(1); ZQR(1)]+Blength*Bframe(:,1);
By = [XQR(1); YQR(1); ZQR(1)]+Blength*Bframe(:,2);
Bz = [XQR(1); YQR(1); ZQR(1)]+Blength*Bframe(:,3);

figure
hold on
% draw Iframe
line([0 Ix(1)],[0 Ix(2)],[0 Ix(3)],'Color','red')
line([0 Iy(1)],[0 Iy(2)],[0 Iy(3)],'Color','green')
line([0 Iz(1)],[0 Iz(2)],[0 Iz(3)],'Color','blue')

% draw init and xdes
plot3(0,0,0,'g+','LineWidth',2)
% plot3(xdes(1),xdes(2),xdes(3),'r+','LineWidth',2)

% draw initial Bframe
hB = plot3(XQR(1),YQR(1),ZQR(1)); %QR initial position
hBx = line([XQR(1) Bx(1)],[YQR(1) Bx(2)],[ZQR(1) Bx(3)],'Color','red');
hBy = line([XQR(1) By(1)],[YQR(1) By(2)],[ZQR(1) By(3)],'Color','green');
hBz = line([XQR(1) Bz(1)],[YQR(1) Bz(2)],[ZQR(1) Bz(3)],'Color','blue');

% draw initial Load
hL = plot3(XL(1),YL(1),ZL(1),'ko','LineWidth',2);

% draw initial QR
% hB = plot3(XQR(1),YQR(1),ZQR(1),'r+','MarkerSize',20); %QR initial position
% hQRx = line([-Bx(1) Bx(1)],[-Bx(2) Bx(2)],[-Bx(3) Bx(3)],'Color','black','LineWidth',2);
% hQRy = line([-By(1) By(1)],[-By(2) By(2)],[-By(3) By(3)],'Color','black','LineWidth',2);
% hQRz = line([-Bz(1) Bz(1)],[-Bz(2) Bz(2)],[-Bz(3) Bz(3)],'Color','black','LineWidth',2);

% draw initial cable
hC = line([XQR(1) XL(1)],[YQR(1) YL(1)],[ZQR(1) ZL(1)],'Color','black');

axis([xmin xmax ymin ymax zmin zmax],'vis3d')
% view(120,30)
% view(-30,20)
view(90,0)
grid on
xlabel('x')
ylabel('y') 
zlabel('z')
% 
% for k=1:length(t)
%     hold on
%     plot3(X(k),Y(k),Z(k),'c+')
% end
for k=1:length(t)
Bx(:,k) = [XQR(k); YQR(k); ZQR(k)] + Blength*(R.signals.values(:,1,k));
By(:,k) = [XQR(k); YQR(k); ZQR(k)] + Blength*(R.signals.values(:,2,k));
Bz(:,k) = [XQR(k); YQR(k); ZQR(k)] + Blength*(R.signals.values(:,3,k));
end

while waitforbuttonpress ~= 0 ; 
  pause(0.01) ; % allow for ctrl-c
end

for k=1:length(t)
set(hB,'xdata',XQR(k),'ydata',YQR(k),'zdata',ZQR(k));
set(hBx,'xdata',[XQR(k) Bx(1,k)],'ydata',[YQR(k) Bx(2,k)],'zdata',[ZQR(k) Bx(3,k)]);
set(hBy,'xdata',[XQR(k) By(1,k)],'ydata',[YQR(k) By(2,k)],'zdata',[ZQR(k) By(3,k)]);
set(hBz,'xdata',[XQR(k) Bz(1,k)],'ydata',[YQR(k) Bz(2,k)],'zdata',[ZQR(k) Bz(3,k)]);

set(hL,'xdata',XL(k),'ydata',YL(k),'zdata',ZL(k));

set(hC,'xdata',[XQR(k) XL(k)],'ydata',[YQR(k) YL(k)],'zdata',[ZQR(k) ZL(k)]);

pause(ts*pausefactor);

% drawnow
end

