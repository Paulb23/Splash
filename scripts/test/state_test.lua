-- test the state api
function init(state, data)
	print("Initilized!")
end

function update(delta)
	splash_state.stop()
end

function events(e)

end

function render()

end

function cleanup(state)

end

local state = splash_state.create("Test State", init, update, events, render, cleanup)
splash_state.add(state)
splash_state.remove("Test State")
splash_state.add(state)
splash_state.start("Test State", "")
splash_state.switch("Test State", "")