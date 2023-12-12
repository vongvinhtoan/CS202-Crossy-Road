#pragma once

#include <Activity.hpp>

class CharacterActivity : public Activity {
public:
    CharacterActivity(ActivityStack& stack, int requestCode, Extra& intent);
    virtual ~CharacterActivity() final override;
    virtual bool handleEvent(sf::Event& event) final override;
    virtual bool handleRealtimeInput() final override;
    virtual bool update(sf::Time dt) final override;
    virtual bool draw() final override;

private:
    CharacterPickerView* mCharacterPickerView = nullptr;
};
