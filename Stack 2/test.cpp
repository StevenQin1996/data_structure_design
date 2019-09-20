   double A = 8.02, B = 19.52, C = -3.7, D;
    Stack<double> S;
    initialize(S);
    push(S,A);
    push(S,B);
    assert(S.size == 2);
    push(S,C);