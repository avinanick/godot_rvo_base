extends KinematicBody


export var destination: Vector2 = Vector2(0,0)
export var speed: float = 1.0
var radius: float = 1.0
var agent_number: int = -1


# Called when the node enters the scene tree for the first time.
func _ready():
	print("I'm ready!")
	agent_setup()
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass

func agent_goal_set():
	var direction: Vector2 = (destination - Vector2(self.global_transform.origin.x, self.global_transform.origin.z)).normalized()
	direction = direction * speed
	CollisionServer.set_agent_preferred_velocity(agent_number, direction.x, direction.y)
	
func agent_position_update():
	var new_position: Vector2 = CollisionServer.get_agent_position(agent_number)
	self.global_transform.origin.x = new_position.x
	self.global_transform.origin.z = new_position.y
	if (destination - Vector2(self.global_transform.origin.x, self.global_transform.origin.z)).length() > radius:
		agent_goal_set()
	else:
		on_goal_reached()

func agent_setup():
	agent_number = CollisionServer.add_collision_agent(self.global_transform.origin.x, self.global_transform.origin.z, radius, speed)
	CollisionServer.connect("simulation_updated", self, "agent_position_update")
	agent_goal_set()
	
func on_goal_reached():
	print("goal reached")
	CollisionServer.set_agent_preferred_velocity(agent_number, 0.0, 0.0)


func on_position_updated(new_position: Vector2):
	# The x and y values should be transformed into x and z, y handled elsewhere
	self.global_transform.origin.x = new_position.x
	self.global_transform.origin.z = new_position.y
	if (destination - Vector2(self.global_transform.origin.x, self.global_transform.origin.z)).length() <= radius:
		on_goal_reached()
