#ifndef RENDERER_DRAWABLE_DRAWABLE_H_
#define RENDERER_DRAWABLE_DRAWABLE_H_

struct Renderer;

class Drawable {
public:
	virtual ~Drawable();
	virtual void draw(const Renderer& renderer) = 0;
};

#endif /* RENDERER_DRAWABLE_DRAWABLE_H_ */
