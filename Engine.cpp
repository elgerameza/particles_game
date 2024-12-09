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
	Time t1 = seconds(0.1f);
	Int32 milli = t1.asMilliseconds(); //100




	cout << "Starting Particle unit tests..." << endl;
	Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
	p.unitTests();
	cout << "Unit tests complete.  Starting engine..." << endl;

	while (m_Window.isOpen())
	{
		Time dt = clock.restart();
		float dtAsSeconds = dt.asSeconds();
		input();
		update(dtAsSeconds);
		draw();
	}
}
void Engine::input()
{
	while (m_Window.isOpen())
	{
		Event event;
		while (m_Window.pollEvent(event))
		{
			if (event.type==Event::MouseButtonPressed == Mouse::Left)
			{
				if (event.mouseButton.button == Mouse::Right)
				{

				}
			}
			else if(event.type == Event::MouseButtonPressed == Mouse::Left) 
			{
				if (event.mouseButton.button == Mouse::Left)
				{

				}
			}
		}
	}
}
void Engine::update(float dtAsSeconds)
{
	for (int i = 0; i < m_particles.size(); i++)
	{
		m_particles[i].update(dtAsSeconds);
		if (> 0.0)
		{
			m_particles.erase(m_particles.begin() + i);
		}
	}
}
void Engine::draw()
{
	m_Window.clear();
	for (int i = 0; i < m_particles.size(); i++)
	{
		
	}
}