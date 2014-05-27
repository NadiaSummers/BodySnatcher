--levelone.lua
--generation calls for world building
--23/04/2014 Nadia Summers

textures = {
	"grass", "textures/ground.png",
	"dirt", "textures/dirt.png",
	"cobble", "textures/cobble.png",
	"stone", "textures/stone.png"
}

terrain = {
	baseTexture = "dirt",
	heightMap = "textures/1024-heightmap.raw",
	size = 1024,
	scaleX = 16,
	scaleY = 2,
	scaleZ = 16
}

terrainLayers = {
	"grass", "textures/1024-grass.raw",
	"cobble", "textures/1024-graveyardpath.raw",
	"stone", "textures/1024-road.raw"
}