#include <iostream>

struct ahanaf{
	public:
		std::string name;
		ahanaf(){}
		ahanaf(std::string &name){
			this->name = name;
		}
		void display()
		{
			std::cout << name << std::endl;
		}
}	object1;

// int main()
// {
// 	object1.name = "ahanaf sama";
// 	object1.display();
// }



// scope operator (::, two colons)

using namespace std;
class Rectangle {
    int width, height;
  public:
    void set_values (int,int);
    int area () {return width*height;}
};

void Rectangle::set_values (int x, int y) {
  width = x;
  height = y;
}

int main () {
  Rectangle rect, rectb;
  rect.set_values (3,4);
  rectb.set_values (5,6);
  cout << "rect area: " << rect.area() << endl;
  cout << "rectb area: " << rectb.area() << endl;
  return 0;
}