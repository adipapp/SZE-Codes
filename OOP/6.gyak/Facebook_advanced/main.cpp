#include "PostManager.hpp"
#include "HtmlView.hpp"
#include "SimpleView.hpp"
#include "View.hpp"
#include "FancyView.hpp"

#include <iostream>
#include <string>

int main(int argc, char** argv){
  PostManager posts_model("Posts.txt");
  list<View*> views;

  switch (argc)
  {
  case 3: if (argv[1] == string("--html")) views.push_back(new HtmlView(posts_model, argv[2]));
		  else if(argv[1] == string("--fancy")) views.push_back(new FancyView(posts_model, argv[2][0]));
		  else std::cerr << "Parameterezesi hiba!";
	  break;
  case 5: if (argv[1] == string("--html") && argv[3] == string("--fancy")) { views.push_back(new HtmlView(posts_model, argv[2])); views.push_back(new FancyView(posts_model, argv[4][0])); }
		  else if (argv[3] == string("--html") && argv[1] == string("--fancy")) { views.push_back(new FancyView(posts_model, argv[2][0])); views.push_back(new HtmlView(posts_model, argv[4])); }
		  else std::cerr << "Parameterezesi hiba!";
	  break;
  default: views.push_back(new SimpleView(posts_model));
	  break;
  }
  
  posts_model.newPost("Grut","I am Grut.");
  
  for(auto& pview : views) {
    pview->printPosts();
    delete pview;
  }
}
