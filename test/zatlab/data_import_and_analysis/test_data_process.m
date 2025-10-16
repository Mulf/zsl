to_str = @(v)(strjoin(arrayfun(@(x) num2str(x), v,'UniformOutput',false),','));

x = [3, 14, 15, 9, 26, 53, 58];

y = smoothdata(x)