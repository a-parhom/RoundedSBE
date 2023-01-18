// own
#include "breezecommon_export.h"

#include <QPainterPath>
#include <QRect>

namespace Breeze {
	class BREEZECOMMON_EXPORT DecorationHelper: public QObject
    {
	    Q_OBJECT

		public:

    	enum { RoundedCorners = 0, SquircledCorners };
    	
		static QPainterPath drawSquircle(float size, int squircleRatio, int translateX=0, int translateY=0, QRect rect=QRect()) ;
	};
}