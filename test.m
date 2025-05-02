
A = [1, 2, 3; 4, 5, 6; 7, 8, 9];
d = 2;
B = [ 1.0 + 2.0i, 2.0 + 2.0i, 3.0 + 2.0i;
      4.0 + 2.0i, 5.0 + 2.0i, 6.0 + 2.0i;
	  7.0 + 2.0i, 8.0 + 2.0i, 9.0 + 2.0i];
c = 1.0 + 2.0i;

A_mul_d = A * d;
A_mul_c = A * c;
B_mul_d = B * d;
B_mul_c = B * c;

disp(to_cpp_mat(A_mul_d))
disp(to_cpp_mat(A_mul_c))
disp(to_cpp_mat(B_mul_d))
disp(to_cpp_mat(B_mul_c))

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

    matstr = "{" + matstr + "}" + newline;
end

function vecstr = to_cpp_vec(v)
    sv = string(v);
    vecstr = "{" + join(sv, ', ') + "}";
    
end