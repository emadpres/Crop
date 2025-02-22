#ifndef __GAME_CLASSIC_H__
#define __GAME_CLASSIC_H__

#include "cocos2d.h"
#include "Geometry/GeometryTypes.h"
class TransformInfo;

class Ball;
class Polygon;

enum class CropperImage
{
    LINE,
    ANGLE
};

class GameClassic : public cocos2d::LayerColor {
public:
    virtual ~GameClassic();
    virtual bool init();

    CREATE_FUNC(GameClassic);

private:
    Ball *_ball;
    Polygon *_polygon;
    cocos2d::DrawNode *_drawing_bg;
    cocos2d::DrawNode *_drawing_poly;

    void RenderPolygon();

    void InitialGameArea();

    cocos2d::Vec2 GetGameAreaCenter();
    cocos2d::Rect GetGameAreaRect();
    cocos2d::Vec2 GetCropperOriginalPos();

    void InitialBall();

    int GetGameAreaSquareWidth();

    void InitCropper();

    CropperImage GetInitialDirection() const;

    void SetCropper();

    cocos2d::Sprite *_cropper;

    cocos2d::Node *_arrows;
    bool _isRotatable;
    cocos2d::Label *_tapLabel;

    void ScaleUpAnimationRunner(float dt);
    void CropperLineAnimationRunner(float dt);
    TransformInfo* _polyTransformInfo;
    Polygon *_targetPolyAfterAnimation;
    cocos2d::Vec2 _targetBallPos;


    double _startingAreaAfterLevelUp, _currentArea;

    int cropperDir;
    bool isCropperLinesValid;
    seg_t _cropperLine1, _cropperLine2;
    cocos2d::Vec2 _cropperLineIntersectionPointWithPoly1, _cropperLineIntersectionPointWithPoly2;

    void IntialBallMovement();

    void UpdateHud(int percentage);

    cocos2d::Label *_levelLabel;
    cocos2d::ProgressTimer *_progressBar;
};


#endif //__GAME_CLASSIC_H__
