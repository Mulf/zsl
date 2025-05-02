
A = [ [1, 2, 3, 4]; [5, 6, 7, 8]; [9, 10, 11, 12]; [13, 14, 15, 16] ];

B = A(3 : -1 : 2 , 3 : -1 : 1);

disp(to_cpp_mat(B))


function matstr =  to_cpp_mat(A)
    sA = string(A);

    matstr = "";
    for i = 1 : size(A, 1)
        sa = "{" + join(sA(i, :), ', ') + "}";
        if i == 1   
            matstr = sa;
        else
            matstr = matstr + "," + newline + sa;
        end
    end

    matstr = "{" + matstr + "}";
end