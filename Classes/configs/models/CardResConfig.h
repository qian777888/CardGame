#ifndef CARD_RES_CONFIG_H
#define CARD_RES_CONFIG_H

#include <string>
#include <array>

// ��ɫ����
enum CardSuitType
{
    CST_NONE = -1,
    CST_CLUBS,      // ÷��
    CST_DIAMONDS,   // ����
    CST_HEARTS,     // ����
    CST_SPADES,     // ����
    CST_NUM_CARD_SUIT_TYPES
};

// ��������
enum CardFaceType
{
    CFT_NONE = -1,
    CFT_ACE,
    CFT_TWO,
    CFT_THREE,
    CFT_FOUR,
    CFT_FIVE,
    CFT_SIX,
    CFT_SEVEN,
    CFT_EIGHT,
    CFT_NINE,
    CFT_TEN,
    CFT_JACK,
    CFT_QUEEN,
    CFT_KING,
    CFT_NUM_CARD_FACE_TYPES
};

// ������Դ������
class CardResConfig {
public:
    // ����ģʽ��ȡ������ʵ��
    static CardResConfig& getInstance() {
        static CardResConfig instance;
        return instance;
    }

    // ��ȡС������Դ·��
    std::string getSmallPointPath(CardFaceType faceType, CardSuitType suitType) const {
        bool isRedSuit = suitType == CST_DIAMONDS || suitType == CST_HEARTS;
        if (faceType >= 0 && faceType < CFT_NUM_CARD_FACE_TYPES) {
            return isRedSuit ? _smallPointPathsRed[faceType] : _smallPointPathsBlack[faceType];
        }
        return "";
    }

    // ��ȡ��ɫ��Դ·��
    std::string getSuitPath(CardSuitType suitType) const {
        if (suitType >= 0 && suitType < CST_NUM_CARD_SUIT_TYPES) {
            return _suitPaths[suitType];
        }
        return "";
    }

    // ��ȡ�������Դ·��
    std::string getLargePointPath(CardFaceType faceType, CardSuitType suitType) const {
        bool isRedSuit = suitType == CST_DIAMONDS || suitType == CST_HEARTS;
        if (faceType >= 0 && faceType < CFT_NUM_CARD_FACE_TYPES) {
            return isRedSuit ? _largePointPathsRed[faceType] : _largePointPathsBlack[faceType];
        }
        return "";
    }

    // ��ȡ��������Դ·��
    std::string getBackgroundPath() const {
        return _backgroundPath;
    }

private:
    // ���캯��˽�л���ʵ�ֵ���ģʽ
    CardResConfig() {
        // ��ʼ��С������Դ·�� - ��ɫ��ɫ
        _smallPointPathsRed[CFT_ACE] = "small_red_A.png";
        _smallPointPathsRed[CFT_TWO] = "small_red_2.png";
        _smallPointPathsRed[CFT_THREE] = "small_red_3.png";
        _smallPointPathsRed[CFT_FOUR] = "small_red_4.png";
        _smallPointPathsRed[CFT_FIVE] = "small_red_5.png";
        _smallPointPathsRed[CFT_SIX] = "small_red_6.png";
        _smallPointPathsRed[CFT_SEVEN] = "small_red_7.png";
        _smallPointPathsRed[CFT_EIGHT] = "small_red_8.png";
        _smallPointPathsRed[CFT_NINE] = "small_red_9.png";
        _smallPointPathsRed[CFT_TEN] = "small_red_10.png";
        _smallPointPathsRed[CFT_JACK] = "small_red_J.png";
        _smallPointPathsRed[CFT_QUEEN] = "small_red_Q.png";
        _smallPointPathsRed[CFT_KING] = "small_red_K.png";

        // ��ʼ��С������Դ·�� - ��ɫ��ɫ
        _smallPointPathsBlack[CFT_ACE] = "small_black_A.png";
        _smallPointPathsBlack[CFT_TWO] = "small_black_2.png";
        _smallPointPathsBlack[CFT_THREE] = "small_black_3.png";
        _smallPointPathsBlack[CFT_FOUR] = "small_black_4.png";
        _smallPointPathsBlack[CFT_FIVE] = "small_black_5.png";
        _smallPointPathsBlack[CFT_SIX] = "small_black_6.png";
        _smallPointPathsBlack[CFT_SEVEN] = "small_black_7.png";
        _smallPointPathsBlack[CFT_EIGHT] = "small_black_8.png";
        _smallPointPathsBlack[CFT_NINE] = "small_black_9.png";
        _smallPointPathsBlack[CFT_TEN] = "small_black_10.png";
        _smallPointPathsBlack[CFT_JACK] = "small_black_J.png";
        _smallPointPathsBlack[CFT_QUEEN] = "small_black_Q.png";
        _smallPointPathsBlack[CFT_KING] = "small_black_K.png";

        // ��ʼ����ɫ��Դ·��
        _suitPaths[CST_CLUBS] = "club.png";
        _suitPaths[CST_DIAMONDS] = "diamond.png";
        _suitPaths[CST_HEARTS] = "heart.png";
        _suitPaths[CST_SPADES] = "spade.png";

        // ��ʼ���������Դ·�� - ��ɫ��ɫ
        _largePointPathsRed[CFT_ACE] = "big_red_A.png";
        _largePointPathsRed[CFT_TWO] = "big_red_2.png";
        _largePointPathsRed[CFT_THREE] = "big_red_3.png";
        _largePointPathsRed[CFT_FOUR] = "big_red_4.png";
        _largePointPathsRed[CFT_FIVE] = "big_red_5.png";
        _largePointPathsRed[CFT_SIX] = "big_red_6.png";
        _largePointPathsRed[CFT_SEVEN] = "big_red_7.png";
        _largePointPathsRed[CFT_EIGHT] = "big_red_8.png";
        _largePointPathsRed[CFT_NINE] = "big_red_9.png";
        _largePointPathsRed[CFT_TEN] = "big_red_10.png";
        _largePointPathsRed[CFT_JACK] = "big_red_J.png";
        _largePointPathsRed[CFT_QUEEN] = "big_red_Q.png";
        _largePointPathsRed[CFT_KING] = "big_red_K.png";

        // ��ʼ���������Դ·�� - ��ɫ��ɫ
        _largePointPathsBlack[CFT_ACE] = "big_black_A.png";
        _largePointPathsBlack[CFT_TWO] = "big_black_2.png";
        _largePointPathsBlack[CFT_THREE] = "big_black_3.png";
        _largePointPathsBlack[CFT_FOUR] = "big_black_4.png";
        _largePointPathsBlack[CFT_FIVE] = "big_black_5.png";
        _largePointPathsBlack[CFT_SIX] = "big_black_6.png";
        _largePointPathsBlack[CFT_SEVEN] = "big_black_7.png";
        _largePointPathsBlack[CFT_EIGHT] = "big_black_8.png";
        _largePointPathsBlack[CFT_NINE] = "big_black_9.png";
        _largePointPathsBlack[CFT_TEN] = "big_black_10.png";
        _largePointPathsBlack[CFT_JACK] = "big_black_J.png";
        _largePointPathsBlack[CFT_QUEEN] = "big_black_Q.png";
        _largePointPathsBlack[CFT_KING] = "big_black_K.png";

        // ��ʼ����������Դ·��
        _backgroundPath = "card_general.png";
    }

    // ��ֹ��������͸�ֵ�����
    CardResConfig(const CardResConfig&) = delete;
    CardResConfig& operator=(const CardResConfig&) = delete;

    // С������Դ·�� std::array - ��ɫ��ɫ
    std::array<std::string, CFT_NUM_CARD_FACE_TYPES> _smallPointPathsRed;
    // С������Դ·�� std::array - ��ɫ��ɫ
    std::array<std::string, CFT_NUM_CARD_FACE_TYPES> _smallPointPathsBlack;
    // ��ɫ��Դ·�� std::array
    std::array<std::string, CST_NUM_CARD_SUIT_TYPES> _suitPaths;
    // �������Դ·�� std::array - ��ɫ��ɫ
    std::array<std::string, CFT_NUM_CARD_FACE_TYPES> _largePointPathsRed;
    // �������Դ·�� std::array - ��ɫ��ɫ
    std::array<std::string, CFT_NUM_CARD_FACE_TYPES> _largePointPathsBlack;
    // ��������Դ·��
    std::string _backgroundPath;
};

#endif    