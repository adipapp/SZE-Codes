#include "FancyView.hpp"
#include <iostream>
using namespace std;

FancyView::FancyView(PostManager& post_model, char delim) :View(post_model), delimiter(delim) {}

void FancyView::printPosts(list<Post> posts) const {
	for (const auto& iter : posts)
	{
		cout << endl<<"\t";
		for (int i = 0; i < 50; i++) cout << delimiter;
		cout << endl <<"\t"<<delimiter<<" "<< iter.getAuthor() << "\n\t\t" <<delimiter << " " << iter.getContent() << endl;
	}

}