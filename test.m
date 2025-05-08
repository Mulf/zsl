% 
% v = [1, 2, 3];
% w = [1.0 + 1.0i, 2.0 + 2.0i, 3.0 + 3.0i];
% d = 2;
% c = 1.0 + 2.0i;
% 
% v_div_d = v ./ d;
% d_div_v = d ./ v;
% v_div_c = v ./ c;
% c_div_v = c ./ v;
% w_div_d = w ./ d;
% d_div_w = d ./ w;
% w_div_c = w ./ c;
% c_div_w = c ./ w;
% 
% % disp("vector_d v_div_d = " + to_cpp_vec(v_div_d) + ";")
% % disp("vector_d d_div_v = " + to_cpp_vec(d_div_v) + ";")
% % disp("vector_d v_div_c = " + to_cpp_vec(v_div_c) + ";")
% % disp("vector_d c_div_d = " + to_cpp_vec(c_div_v) + ";")
% % disp("vector_d w_div_d = " + to_cpp_vec(w_div_d) + ";")
% % disp("vector_d d_div_w = " + to_cpp_vec(d_div_w) + ";")
% % disp("vector_d w_div_c = " + to_cpp_vec(w_div_c) + ";")
% % disp("vector_d c_div_w = " + to_cpp_vec(c_div_w) + ";")
% 
% v = [1, 2, 3];
% a = [2, 2, 2];
% w = [1.0 + 1.0i, 2.0 + 2.0i, 3.0 + 3.0i];
% b = [1.0 + 2.0i, 1.0 + 2.0i, 1.0 + 2.0i];
% 
% v_div_a = v ./ a;
% w_div_b = w ./ b;
% v_div_w = v ./ w;
% w_div_v = w ./ v;
% 
% % disp("v_div_a" + to_cpp_vec(v_div_a) + ";")
% % disp("w_div_b" + to_cpp_vec(w_div_b) + ";")
% % disp("v_div_w" + to_cpp_vec(v_div_w) + ";")
% % disp("w_div_v" + to_cpp_vec(w_div_v) + ";")
% 
% A = [1, 2, 3; 4, 5, 6; 7, 8, 9];
% d = 2;
% B = [[1.0 + 2.0i, 2.0 + 2.0i, 3.0 + 2.0i];
%     [4.0 + 2.0i, 5.0 + 2.0i, 6.0 + 2.0i];
%     [7.0 + 2.0i, 8.0 + 2.0i, 9.0 + 2.0i]];
% c = 1.0 + 2.0i;
% 
% A_div_d = A ./ d;
% d_div_A = d ./ A;
% A_div_c = A ./ c;
% c_div_A = c ./ A;
% B_div_d = B ./ d;
% d_div_B = d ./ B;
% B_div_c = B ./ c;
% c_div_B = c ./ B;
% 
% disp("matrix_c A_div_d" + to_cpp_mat(A_div_d) + ";") 
% disp("matrix_c d_div_A" + to_cpp_mat(d_div_A) + ";") 
% disp("matrix_c A_div_c" + to_cpp_mat(A_div_c) + ";") 
% disp("matrix_c c_div_A" + to_cpp_mat(c_div_A) + ";") 
% disp("matrix_c B_div_d" + to_cpp_mat(B_div_d) + ";") 
% disp("matrix_c d_div_B" + to_cpp_mat(d_div_B) + ";") 
% disp("matrix_c B_div_c" + to_cpp_mat(B_div_c) + ";") 
% disp("matrix_c c_div_B" + to_cpp_mat(c_div_B) + ";") 

A = magic(4);
disp(to_cpp_mat(A))

function matstr =  to_cpp_mat(A)
    sA = add_dot_mat(string(A));

    matstr = "";
    for i = 1 : size(A, 1)
        sa = "{" + join(sA(i, :), ', ') + "}";
        if i == 1   
            matstr = sa;
        else
            matstr = matstr + "," + newline + sa;
        end
    end

    matstr = "{" + matstr + "}" ;
end

function vecstr = to_cpp_vec(v)
    sv = string(v);
    vecstr = "{" + join(sv, ', ') + "}";
end

function snum = add_dot_num(snum)
     if ~contains(snum, '.')
         if ~endsWith(snum, 'i')
            snum = strcat(snum, ".0");
         else
            snum = strcat(extractBefore( snum, 'i'), ".0i" );
         end
     end
end

function sA = add_dot_mat(sA)
    for i = 1 : size(sA, 1)
        for j = 1 : size(sA, 2)
            sA(i, j) = add_dot_num(sA(i, j));
        end
    end
end