x = [-3 -2 -1 0 1 2 3];
v = 3*x.^2;
xq = [-4 -2.5 -0.5 0.5 2.5 4];
% vq = interp1(x,v,xq,'pchip',27)
vq = interp1(x,v,xq,'cubic',27)
