-- test the render api
local window = splash_window.create("Hello World", 800, 600)

function init(state, data)
	
end

function update(delta)

end

function events(e)

end

function render()
	splash_renderer.clear(window, 0, 255, 0)
end

function cleanup(state)

end

local state = splash_state.create("Test State", init, update, events, render, cleanup)
splash_state.add(state)
splash_state.start("Test State", "")