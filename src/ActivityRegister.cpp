#include <Application.hpp>
#include <ActivityList.hpp>

void Application::registerActivities()
{
	m_activityStack->registerActivity<MainActivity>(ActivityID::Main);
	m_activityStack->registerActivity<MenuActivity>(ActivityID::Menu);
	m_activityStack->registerActivity<SettingActivity>(ActivityID::Setting);
}
