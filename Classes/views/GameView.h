#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include "cocos2d.h"
#include "GameModel.h"
#include <unordered_map>
#include "CardView.h"
class GameView : public cocos2d::Layer {
public:
    static GameView* create();
    bool init();

    void showMatchSuccessAnimation();
    CardView* findCardViewById(int cardId);
    void addCardView(CardView* cardView);

private:
    std::unordered_map<int, CardView*> _cardViewMap;
    cocos2d::Rect _mainAreaRect;
    cocos2d::Rect _pileAreaRect;
};

#endif 
