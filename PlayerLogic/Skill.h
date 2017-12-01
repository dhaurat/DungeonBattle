//
// Created on 03/11/2017.
//

#ifndef NUMKINCH_SKILL_H
#define NUMKINCH_SKILL_H

/**
 * Set defining the number of points of a certain characteristic of a character (attack, defense, agility, life, ...),
 * in relation to a maximum number of points.
 */
class Skill {

private:
    int _maxValue;

    int _value;

public:
    Skill();

    /**
     * If the value or the maxValue are inferior to 0 (i.e. non-valid), they are both set to 0.
     *
     * @param value the base number of points of the given Skill.
     * @param maxValue the maximum number of points of the given Skill.
     */
    Skill(int value, int maxValue);

    int getValue() const;

    int getMaxValue() const;

    void setValue(int val);

    void setMaxValue(int maxVal);

    void alterPoints(int val);

    void alterMaxPoints(int maxVal);
};

#endif //NUMKINCH_SKILL_H
