	std::string name[]={"BLACK","RED","GREEN","YELLOW","BLUE","MAGENTA","CYAN","WHITE"};
    for (int i=0; i<8; i++) {
        Color j = (Color)((i+1)%8);
    Shape * s1[]={new Box(RED,2,5,9,3),new Circle(CYAN,2,2,2)};
    Group * g = new Group((Color)i,2,s1);
    std::stringstream ss;
    g->render(ss);
	g->color(j);
    ss.str("");
    g->render(ss);
	Shape * s2[]={new Box(CYAN,1,2,2,1),g,new RoundBox(CYAN,2,2,2,2,2)};
	Group h((Color)i,3,s2);
    ss.str("");
    h.render(ss);
    assert(ss.str() == "Group(" + name[i] + ",3,Box(" + name[i] + ",1,2,2,1),Group(" + name[i] + ",2,Box("+name[i]+",2,5,9,3),Circle("+name[i]+",2,2,2)),RoundBox("+name[i]+",2,2,2,2,2))");
	h.color(j);
    ss.str("");
    h.render(ss);
    }