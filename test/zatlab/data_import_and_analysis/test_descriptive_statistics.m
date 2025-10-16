to_str = @(v)(strjoin(arrayfun(@(x) num2str(x), v,'UniformOutput',false),','));


x = [ -0.2050   -0.1241    1.4897    1.4090    1.4172    0.6715];
y = [ -1.2075    0.7172    1.6302    0.4889    1.0347    0.7269];
R = corrcoef(x, y);
R = cov(x, y);

%% movemean
x = [3, 14, 15, 9, 26, 53, 58];

mad3 = movmad(x, 3);
mad4 = movmad(x, 4);
m3 = to_str(mad3)
m4 = to_str(mad4)


max3 = movmax(x, 3);
max4 = movmax(x, 4);
m3 = to_str(max3);
m4 = to_str(max4);

mean3 = movmean(x, 3);
mean4 = movmean(x, 4);

median3 = movmedian(x, 3);
median4 = movmedian(x, 4);
m3 = to_str(median3);
m4 = to_str(median4);

min3 = movmin(x, 3);
min4 = movmin(x, 4);
m3 = to_str(min3);
m4 = to_str(min4);

std3 = movstd(x, 3);
std4 = movstd(x, 4);
m3 = to_str(std3);
m4 = to_str(std4);

sum3 = movsum(x, 3);
sum4 = movsum(x, 4);
m3 = to_str(sum3);
m4 = to_str(sum4);

var3 = movvar(x, 3);
var4 = movvar(x, 4);
m3 = to_str(var3);
m4 = to_str(var4);

