#include "PostList.hpp"
#include <cstdio>

int main(){
  PostList postlist("Posts.txt");
  postlist.printAll();
  postlist.printBy("T-800");
  double d = 12.0625;
  printf("%07.4f\n", d);
}
