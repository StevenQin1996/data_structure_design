int main()
{
    /*double pts[] = {0,0,1,0,0,1,1,1,0,2};
    Box b(BLUE,-1,1,1,-1);
    Circle c(BLACK,5,5,2);
    Triangle t(RED,0,0,10,0,0,1);
    Polygon p(YELLOW,pts,5);
    Line l(WHITE,0,1,5,7.6);
    RoundBox rb(MAGENTA,-1,3,4,2,1.5);
    b.move(-2, -.5);//-3,.5, -1, -1.5
    c.move(-.5, 2.5);//(4.5, 7.5)
    t.move(.5, .75);//(.5,.75), (10.5, .75), (.5, 1.75)
    p.move(-1, 2.5);// (-1, 2.5), (0, 2.5), (-1, 3.5), (0, 3.5), (-1, 4.5)
    l.move(-.5,3);//-.5, 4, 4, 10.6
    rb.move(1,2);
    //assert(l.end1Y() == 4);
    cout<<"l.end1Y: "<<l.end1Y()<<endl;*/
    
    Box b(BLUE,1,4,3,2);
    Circle c(BLUE,1,2,3);
    Triangle t(BLUE,1,2,3,4,3,2);
    double pts[] = {1,2,3,5,5,6,5,3,4,1};
    Polygon p(BLUE,pts,5);
    RoundBox rb(WHITE,0,3,4,0,1);
     if (rb.inside(2.96,3.96)){
        cout << "(2.96,3.96) is inside "; c.render(cout); cout<<std::endl;
     }
    else
        cout << "(2.96,3.96) is NOT inside ";  c.render(cout);  cout<<std::endl;
    //assert(!rb.inside(2.96,3.96));
    
    
}