-- test the window api
local window = splash_window.create("Hello World", 800, 600)
splash_window.setTitle(window, "New Title")
splash_window.setBrightness(window, 0.2);
splash_window.setPosition(window, 1920, 1080)
splash_window.setPosition(window, 100, 100)
splash_window.setBorderless(window, true)
splash_window.setVisible(window, false)
splash_window.setVisible(window, true)
splash_window.setResizable(window, true)
assert(splash_window.getTitle(window) == "New Title","Error setting Title");
local pos = splash_window.getPosition(window)
assert(pos["x"] == 100, "Failed to get x position");
assert(pos["y"] == 100, "Failed to get y position");
local size = splash_window.getSize(window)
assert(size["w"] == 800, "Failed to get width");
assert(size["h"] == 600, "Failed to get hight");
splash_window.destroy(window)