%%
% 
%  PREFORMATTED
%  TEXT
% 
clear
clc
clf
tic
L=100; % space grid
T=200;  % time grid
dx=1/L; % space step
dt=0.01; % time step
v=0.8; % wave speed
c=v^2*dt^2/dx^2; % reduced coeffecient
u=zeros(T,L+1);

for k=1:L/2+1
  u(1,k)=sin(4*pi*(k-1)/L); % initial wave shape
  u(2,k)=sin(4*pi*(k-1)/L); % initial velocity = 0
end

for j=2:T
  for k=2:L
    u(j+1,k)=c*(u(j,k+1)+u(j,k-1))+2*(1-c)*u(j,k)-u(j-1,k);
    u(j,L+1)=u(j,L);
  end
    u(j+1,L+1)=c*(u(j,L))+2*(1-c)*u(j,L+1)-u(j-1,L+1);
end

xx=linspace(0,1,L+1);

h = figure;
axis tight manual % this ensures that getframe() returns a consistent size
filename = '1Dwave.gif';
for j=1:T
    pic1=plot(xx,u(j,:),'r-o');
    hold on ;
    %---------------%
    set(gca,'XLim',[0 1])
    set(gca,'YLim',[-2 2])
    set(gca,'XGrid','on')
    set(gca,'YGrid','on')
    set(get(gca, 'XLabel'), 'String', 'x')
    set(get(gca, 'XLabel'), 'FontSize', 16)
    set(get(gca, 'XLabel'), 'FontName', 'Times New Roman')
    set(get(gca, 'YLabel'), 'String', 'u(x,t)')
    set(get(gca, 'YLabel'), 'FontSize', 16)
    set(get(gca, 'YLabel'), 'FontName', 'Times New Roman')
    set(get(gca, 'Title'), 'String', ['t=',num2str(j*dt),'s'])
    set(get(gca, 'Title'), 'FontSize', 18)
    set(get(gca, 'Title'), 'FontName', 'Times New Roman')
    %---------------%
    drawnow;
    % Capture the plot as an image 
    frame = getframe(h); 
    im = frame2im(frame); 
    [im,cm] = rgb2ind(im,256);
    % Write to the GIF File 
    if j == 1 
        imwrite(im,cm,filename,'gif', 'Loopcount',inf,'delaytime',0.2); 
    else 
        imwrite(im,cm,filename,'gif','WriteMode','append','delaytime',0.2); 
    end
    delete(pic1);
end

toc