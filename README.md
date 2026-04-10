🧠 Mini Game Engine (C++)

🎮 Not just a game… but a scalable game architecture.

🚀 Overview

✨ This project is a mini game engine built in C++ using a Component-Based Architecture.

📌 Instead of building a single game, this project focuses on designing a
reusable and scalable system that can be used to create different types of games.

🎯 Key Concepts
🧩 Concept	💡 Description
🧩 Component-Based Design	تقسيم السلوك إلى أجزاء مستقلة
🧠 Separation of Concerns	فصل المسؤوليات
♻️ Reusability	إعادة استخدام الكود
📦 Modular Architecture	نظام مرن وقابل للتوسعة
⚙️ Game Loop System	قلب المحرك
🧱 Architecture
🧍 GameObject

✨ Represents any entity in the game
🎮 Player | 👾 Enemy | 🤖 NPC

🔌 Component

💡 Each behavior is separated into components:

🏃 Movement Component
🎨 Render Component
💥 Physics Component
🎮 Input Component

📌 A GameObject is just a collection of Components.

🔁 Game Loop
while (true) {
    gameObject.update();
}

✨ Each component updates independently
→ 🎯 Clean separation of logic

💡 Why This Project?

🚀 Most beginner projects focus on building a game.
🧠 This project focuses on building the system behind the game.

👉 This demonstrates:

🧠 Strong understanding of OOP
🏗️ Real-world software architecture thinking
✨ Clean and maintainable code design
🔥 Features
⚡ Feature	📌 Description
➕ Add Components	إضافة مكونات بشكل ديناميكي
➖ Remove Components	حذف مكونات
♻️ Extendable	قابل للتوسعة
🧼 Clean Structure	كود نظيف وواضح
🚀 Scalable	قابل للتطوير
🧪 Example Usage
GameObject player;

player.addComponent(new MovementComponent());
player.addComponent(new RenderComponent());
player.addComponent(new PhysicsComponent());
player.addComponent(new InputComponent());

player.update();
🛠️ Technologies
💻 C++
🧠 Object-Oriented Programming (OOP)
📈 Future Improvements
🌍 Scene Management System
📡 Event System
💥 Collision Detection
📍 Transform Component (Position / Rotation)
🧠 Full Entity Component System (ECS)
👩‍💻 Author

✨ Rawan Aldawsari

⭐ Final Note

🚀 This project represents a shift from writing code to
🧠 engineering systems
