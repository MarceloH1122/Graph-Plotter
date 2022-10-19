#include <SFML/Graphics.hpp>

using namespace sf;

class Axis : public Drawable
{
    RectangleShape _X, _Y;
    float stroke = 2;

public:
    Axis() : _X(Vector2f(UINT_MAX, 2)), _Y(Vector2f(2, UINT_MAX))
    {
        _X.setFillColor(Color::Black);
        _X.setPosition(-INT_MAX / 2, -stroke / 2);
        _Y.setFillColor(Color::Black);
        _Y.setPosition(-stroke / 2, -INT_MAX / 2);
    }

    void changeStroke(float _stroke)
    {
        stroke = _stroke;

        _X.setSize(Vector2f(INT_MAX, stroke));
        _X.setPosition(-INT_MAX / 2, -stroke / 2);

        _Y.setSize(Vector2f(stroke, INT_MAX));
        _Y.setPosition(-stroke / 2, -INT_MAX / 2);
    }

    float getStroke()
    {
        return stroke;
    }

    // Overwrite

    void draw(RenderTarget &target, RenderStates states) const
    {
        target.draw(_Y, states);
        target.draw(_X, states);
    }
};