
-- we have 3 types of widgets now: button, input, label
-- parameters for button: type, x, y, h, w, text
-- parameters for input: type, x, y, h, w
-- parameters for label: type, x, y, text, character size
-- use Lua syntax to avoid errors: after EVERY widget parameters
-- and after EVERY defintion of widget except last, at the end insert comma

frame1 = {
	countWidgets = 3, -- the amount of widgets in this frame
	widget1 = { x = 100, y=100, typeOfWidget = "button", h =50, w = 100, text = "I'M BUTTON" },
	widget2 = { x = 220, y=225, typeOfWidget = "input", h = 40, w = 200},
	widget3 = { x = 300, y=300, typeOfWidget = "label", text = "LABEL", characterSize = 14} -- here comma not need
}

frame2 = {
	countWidgets = 4,  --the amount of widgets in this frame
	widget1 = { x = 50, y = 100, typeOfWidget = "input", h = 40, w = 300},
	widget2 = { x = 50, y = 200, typeOfWidget = "input", h = 40, w = 300},
	widget3 = { x = 50, y = 300, typeOfWidget = "input", h = 40, w = 300},
	widget4 = { x = 400, y = 100, typeOfWidget = "button", h = 40, w = 100, text = "Insert I" } -- here comma not need
}
