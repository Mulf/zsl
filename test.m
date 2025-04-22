
I = eye(2,3);

disp(to_cpp_mat(I))


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