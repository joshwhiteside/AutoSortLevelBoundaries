#Author Josh Whiteside 18/9/2019
import unreal

def get_all_level_boundaries():
	r = unreal.GameplayStatics.get_all_actors_of_class(unreal.EditorLevelLibrary.get_editor_world(),unreal.LevelStreamingVolume)
	return r

def get_closest_level_boundary(a,boundaries):
	largestLength = 99999999999 #that should do it.

	for b in boundaries:
		tempVector = b.get_actor_transform().translation.subtract(a.get_actor_transform().translation)
		tempLength = tempVector.length()

		if tempLength < largestLength:
			l = b
			largestLength = tempLength
	return l

def main():
	selected_actors = unreal.EditorLevelLibrary.get_selected_level_actors()
	level_boundaries = get_all_level_boundaries()

	total_frames = len(selected_actors)
	text_label = "Sorting objects"

	with unreal.ScopedSlowTask(total_frames, text_label) as slow_task:
		slow_task.make_dialog(True)
	
		for x in selected_actors:
			if slow_task.should_cancel():         
				break
				
			b = get_closest_level_boundary(x, level_boundaries)	
	
			#Calls c++ function that will find the level streaming of the respective name
			ls = unreal.LevelBoundarySortUtilities.get_level_streaming_from_name(b.streaming_level_names[0],x)			
			a = [x] #Puts the current actor in an array for move actors to level (EditorLevelUtils wants it in an array)

			#moves actors to level
			unreal.EditorLevelUtils.move_actors_to_level(a,ls,True)
			slow_task.enter_progress_frame(1)
			
main()