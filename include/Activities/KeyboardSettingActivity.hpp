#pragma once

#include <Activity.hpp>
#include <set>

class KeyboardSettingActivity : public Activity
{
public:
    KeyboardSettingActivity(ActivityStack &stack, int requestCode, Extra &intent);
    virtual ~KeyboardSettingActivity() final override;
    virtual bool handleEvent(sf::Event &event) final override;
    virtual bool handleRealtimeInput() final override;
    virtual bool update(sf::Time dt) final override;
    virtual bool draw() final override;

private:
    ShortcutView* m_shortcutView;
    RectangleView* m_shortcutPicture;
};
