	#include "Engine.h"

Engine::Engine()
{
	VideoMode vm(1920,1080);
	m_Window.create(vm,"particles pj", Style::Default);
	
}
void Engine::run()
{
	Clock clock;
	Time time1 = clock.getElapsedTime();
	Time time2 = clock.restart();
}
void Engine::input()
{
	Event event;
	if (event.mouseButton.button == sf::Mouse::Left)
	{

	}
}
void Engine::update(float dtAsSeconds)
{
	for (int i = 0; i < m_particles.size(); i++)
	{
		if(m_particles)
	}
}
void Engine::draw()
{

}