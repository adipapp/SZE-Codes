#ifndef FANCYVIEW_HPP
#define FANCYVIEW_HPP

#include "View.hpp"

class FancyView : public View
{
public:
	FancyView(PostManager& post_model, char delimiter);
	
protected:
	virtual void printPosts(list<Post> posts) const;

private:
	char delimiter;
};


#endif
