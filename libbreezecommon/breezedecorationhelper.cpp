#include "breezedecorationhelper.h"

namespace Breeze {
	
	QPainterPath
	DecorationHelper::drawSquircle(float size, int squircleRatio, int translateX, int translateY, QRect rect)
	{
	    QPainterPath squircle;
	    float squircleSize = size * 2 * (float(squircleRatio)/24.0 * 0.25 + 0.8); //0.8 .. 1.05
	    float squircleEdge = (size * 2) - squircleSize;

	    int rect_width = (rect.width() - 2 * size) <= 0 ? 0 : (rect.width() - 2 * size) ;
	    int rect_height = (rect.height() - 2 * size) <= 0 ? 0 : (rect.height() - 2 * size) ;

	    squircle.setFillRule(Qt::WindingFill);

	    squircle.moveTo(size + rect_width, 0);
	    squircle.cubicTo(QPointF(squircleSize + rect_width, 0), QPointF(size * 2 + rect_width, squircleEdge), QPointF(size * 2 + rect_width, size));
	    squircle.lineTo(size * 2 + rect_width, size + rect_height);
	    squircle.cubicTo(QPointF(size * 2 + rect_width, squircleSize + rect_height), QPointF(squircleSize + rect_width, size * 2 + rect_height), QPointF(size+ rect_width, size * 2 + rect_height));
	    squircle.lineTo(size, size * 2 + rect_height);
	    squircle.cubicTo(QPointF(squircleEdge, size * 2 + rect_height), QPointF(0, squircleSize + rect_height), QPointF(0, size + rect_height));
	    squircle.lineTo(0, size);
	    squircle.cubicTo(QPointF(0, squircleEdge), QPointF(squircleEdge, 0), QPointF(size, 0));

	    squircle.translate(translateX + rect.x(), translateY + rect.y());

	    return squircle;
	}

}