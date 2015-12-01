import java.io.*;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class Passingbook {
	public static void findfriendpass(int N, HashMap<Integer, ArrayList<Integer>> friends)
	{
		int[] path = new int[N];
		path[0] = 1;
		
		if(findfriendpass_aux(N, friends, path, 1))
		{
			for(int people:path)
				System.out.println(people);
			System.out.println(1);
		}
			
		else
			System.out.println("No Solution");
	}
	 
	public static boolean findfriendpass_aux(int N, HashMap<Integer, ArrayList<Integer>> friends, int[] path, int pos)
	{
		if(pos == N)
		{
			if(friends.get(path[pos - 1]).contains(1))
				return true;
			else
				return false;
		}
		
		for(int v = 1; v <= N; v++)
		{
			if(isOKtoAdd(v, friends,path,pos))
			{
				path[pos] = v;
				
				if(findfriendpass_aux(N, friends, path,pos + 1))
					return true;
				
				path[pos] = 0;
			}
		}
	
		return false;
	}
	
	public static boolean isOKtoAdd(int v, HashMap<Integer,ArrayList<Integer>> friends, int[] path, int pos)
	{
		if(!friends.get(path[pos - 1]).contains(v))
			return false;
		for(int item:path)
			if(item == v)
				return false;
		
		return true;		
	}
	
	public static void main(String[] args)
	{
		HashMap<Integer, ArrayList<Integer>> friends = new HashMap<Integer, ArrayList<Integer>>();
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")));
			int N = Integer.parseInt(br.readLine());
			
			for(int i = 1; i <= N; i++)
			{
				IntStream friend_intstream = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt);
				ArrayList<Integer> friend = (ArrayList<Integer>) friend_intstream.boxed().collect(Collectors.toList());
				friends.put(i, friend);
			}
			findfriendpass(N, friends);
			
			
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
