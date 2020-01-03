local class = require "middleclass"
local PanelBase = class("PanelBase")
local def = PanelBase
def.m_panelName = ""
def.m_panelPath = ""
def.m_panel = nil

def.CreatePanel = function(self, path)
    print(def, "CreatePanel")

    self:OnCreate()
end

def.DestroyPanel = function(self)
end

def.OnCreate = function(self)
end

def.OnDestroy = function(self)
end

return PanelBase