#ifndef __Layer__
#define __Layer__

class Layer
{
public:
	
	virtual void render() = 0;
	virtual void update() = 0;
	
protected:

	virtual ~Layer() {}
	
};

#endif // __Layer__
