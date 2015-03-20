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
print(splash_window.getTitle(window))
local pos = splash_window.getPosition(window)
print("Position x: " .. pos["x"])
print("Position y: " .. pos["y"])
local size = splash_window.getSize(window)
print("Width: " .. size["w"])
print("Height: " .. size["h"])
while true do

end

splash_window.destroy(window)