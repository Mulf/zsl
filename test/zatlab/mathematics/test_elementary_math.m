v = linspace(0, 8, 50);
w = readmatrix("w.csv");
% 
% figure
% plot(v, w)

X = readmatrix("X.csv");
Y = readmatrix("Y.csv");
figure
plot(X(1, :), Y(1, :))
hold on
plot(X(1, :), Y(2, :))