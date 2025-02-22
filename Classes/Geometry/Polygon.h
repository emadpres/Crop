#ifndef __POLYGON_H__
#define __POLYGON_H__

#include <list>
#include "cocos2d.h"
#include "GeometryTypes.h"
class TransformInfo;


class Polygon {

public:
    Polygon(cocos2d::Vec2 origin, cocos2d::Size area);

    Polygon(const Polygon &p);

    Polygon &operator=(const Polygon &second);

    void Initial_Square(cocos2d::Vec2 leftBottom, int width);

    void Initial_Custom1(cocos2d::Vec2 leftBottom, int width);

    const segList_t &GetSegments() const;
    segList_t &GetSegments();

    void AddSegment(seg_t seg);

    void Crop(cocos2d::Vec2 pos, int dir, cocos2d::Vec2 ballPos, cocos2d::Vec2 &removedSideCenter);

    bool IsPointInsidePolygon(cocos2d::Vec2 point) const;

    float CalcArea();

    cocos2d::Vec2 GetCenter();

    TransformInfo* EstimateScaleUp();
    void ScaleUp(TransformInfo *ti);

    cocos2d::Vec2 RayPos(cocos2d::Vec2 startPos, cocos2d::Vec2 dir);

private:
    cocos2d::Vec2 _origin;
    cocos2d::Size _area;
    segList_t _segments;

    segListIterator_t Ray(cocos2d::Vec2 startPos, cocos2d::Vec2 dir);

    int RayCount(cocos2d::Vec2 startPos, cocos2d::Vec2 dir) const;

    float FindIntersectionPoint(cocos2d::Vec2 a_start, cocos2d::Vec2 a_end, cocos2d::Vec2 b_start, cocos2d::Vec2 b_end) const;

    void FindBoundaryXY(float &x_min, float &x_max, float &y_min, float &y_max);

    cocos2d::Vec2 BreakSegment(segListIterator_t it, float breakRatio);

    void SplitPolygon(cocos2d::Vec2 &pos, const segListIterator_t &it1, const segListIterator_t &it2,
                      cocos2d::Vec2 &rayCollisionPoint1, cocos2d::Vec2 &rayCollisionPoint2, Polygon *&poly1,
                      Polygon *&poly2) const;
};


#endif //__POLYGON_H__
