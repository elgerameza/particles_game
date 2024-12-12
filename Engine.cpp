#include "Engine.h"

Engine::Engine()
{
	VideoMode vm = VideoMode::getDesktopMode();
	m_Window.create(vm, "particles pj", Style::Default);

}
void Engine::run()
{
	Clock clock;

	cout << "Starting Particle unit tests..." << endl;
	Particle p(m_Window, 4, { (int)m_Window.getSize().x, (int)m_Window.getSize().y });
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
	Event event;
	while (m_Window.pollEvent(event)) {
		// Handle window close event
		if (event.type == Event::Closed) {
			m_Window.close();
		}
		// Handle key pressed event
		else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
			m_Window.close();
		}
		// Handle left mouse button pressed event
		else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
			Vector2i mousePos = Mouse::getPosition(m_Window);
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
	for (auto i = m_particles.begin(); i != m_particles.end();) {
		if (i -> getTTL() > 0.0) {
			i -> update(dtAsSeconds);
			++i; // Only increment if no particle is erased
		}
		else {
			i = m_particles.erase(i); // Erase and keep the index at the same position
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