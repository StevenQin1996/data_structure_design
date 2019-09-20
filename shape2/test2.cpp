int main()
{
    Box b(BLUE,1,4,3,2);
    Circle c(BLUE,1,2,3);
    Triangle t(BLUE,1,2,3,4,3,2);
    double pts[] = {1,2,3,4,5,6,7,8,9,10};
    Polygon p(BLUE,pts,5);
    Box bb(BLUE,0,1,1,0);
    Circle cc(BLACK,5,5,2);
    Triangle tt(RED,0,0,10,0,0,1);
    double pts2[] = {0,0,1,0,1,1, 0,2,0,1};
    Polygon pp(YELLOW,pts2,5);
    RoundBox rb(WHITE,0,3,4,0,1);
    cout<<rb.thickness()<<endl;
    double answer = (8.0+M_PI)/(6.0+2.0*M_PI);
    cout<<"answer: "<<answer<<endl;
    cout<<"a: "<<rb.thickness()-answer<<endl;
    //cout<<"fabs(rb.thickness()-((8.0+M_PI)/(6.0+2.0*M_PI)): "<<rb.thickness()-((8.0+M_PI)/(6.0+2.0*M_PI)<<endl;
    //assert(fabs(rb.thickness()-((8.0+M_PI)/(6.0+2.0*M_PI))) < 0.0000001);//wrong

    /*Box b(BLUE,1,4,3,2);
    Circle c(BLUE,1,2,3);
    Triangle t(BLUE,1,2,3,4,3,2);
    double pts[] = {1,2,3,5,5,6,5,3,4,1};
    Polygon p(BLUE,pts,5);
    RoundBox rb(WHITE,0,3,4,0,1);
     if (rb.inside(2.96,3.96)){
        cout << "(2.96,3.96) is inside "; c.render(cout); cout<<std::endl;
     }
    else
        cout << "(2.96,3.96) is NOT inside ";  c.render(cout);  cout<<std::endl;*/
    //assert(!rb.inside(2.96,3.96));//wrong
}