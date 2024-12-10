#include "Engine.h"

Engine::Engine()
{
	VideoMode vm(1920,1080);
	m_Window.create(vm,"particles pj", Style::Default);
	
}
void Engine::run()
{
	Clock clock;

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
	sf::Event event;
	while (m_Window.pollEvent(event)) {
		// Handle window close event
		if (event.type == sf::Event::Closed) {
			m_Window.close();
		}
		// Handle key pressed event
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
			m_Window.close();
		}
		// Handle left mouse button pressed event
		else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
			sf::Vector2i mousePos = sf::Mouse::getPosition(m_Window);
			// Create 5 particles
			for (int i = 0; i < 5; ++i) {
				int numPoints = rand() % 26 + 25; // Random number in range [25:50]
				m_particles.emplace_back(m_Window, numPoints, mousePos);
			}
		}
	}
}
void Engine::update(float dtAsSeconds)
{
	for (int i = 0; i < m_particles.size();) {
		if (m_particles[i].getTTL() > 0.0f) {
			m_particles[i].update(dtAsSeconds);
			++i; // Only increment if no particle is erased
		}
		else {
			m_particles.erase(m_particles.begin() + i); // Erase and keep the index at the same position
		}
	}
}
void Engine::draw()
{
	m_Window.clear();
	for (const auto& particle : m_particles) {
		m_Window.draw(particle); // Draw each particle
	}
	m_Window.display();
}