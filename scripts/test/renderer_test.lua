-- test the window api
local window = splash_window.create("Hello World", 800, 600)
while true do
	splash_renderer.clear(window, 0, 255, 0)
end
splash_window.destroy(window)