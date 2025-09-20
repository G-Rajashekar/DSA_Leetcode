class Packet{
    int source,destination,timestamp;

    Packet(int s,int d,int t){
        this.source=s;
        this.destination=d;
        this.timestamp=t;
    }
}

class Router {
    int memoryLimit;
    Deque<Packet> packets;
    Set<String>packetSet;
    Map<Integer,ArrayList<Integer>>destTimestamps;
    Map<Integer,Integer>startIndexes;
    public Router(int memoryLimit) {
        this.memoryLimit=memoryLimit;
        this.packets=new ArrayDeque<>();
        this.packetSet=new HashSet<>();
        this.destTimestamps=new HashMap<>();
        this.startIndexes=new HashMap<>();
    }
    public String makeKey(int source,int destination,int timestamp){
        return source+"#"+destination+"#"+timestamp;
    }

    public boolean addPacket(int source, int destination, int timestamp) {
        String key=makeKey(source,destination,timestamp);

        if (packetSet.contains(key)) return false;

        if (packets.size()>=memoryLimit){
             forwardPacket();
        }
        Packet p=new Packet(source,destination,timestamp);
        packets.offerLast(p);
        key=makeKey(source,destination,timestamp);
        packetSet.add(key);
        if (!destTimestamps.containsKey(destination)){
            destTimestamps.put(destination,new ArrayList<>());
        }
        destTimestamps.get(destination).add(timestamp);
         if (!startIndexes.containsKey(destination)) startIndexes.put(destination,0);
        return true;
        
    }
    
    public int[] forwardPacket() {
        if (packets.isEmpty()) return new int[]{};

        Packet p=packets.pollFirst();
        String key=makeKey(p.source,p.destination,p.timestamp);
        packetSet.remove(key);
        int index=startIndexes.get(p.destination);
        startIndexes.put(p.destination,index+1);
        return new int[]{p.source,p.destination,p.timestamp};
    }
    
    public int getCount(int destination, int startTime, int endTime) {
          if (!destTimestamps.containsKey(destination)){
            return 0;
          }
          ArrayList<Integer>li=destTimestamps.get(destination);
          int idx=startIndexes.get(destination);
          int left=lower_bound(li,startTime,idx);
          int right=upper_bound(li,endTime,idx);

          return right-left;
    }

    int lower_bound(ArrayList<Integer>li,int target,int idx){
        int low=idx;
        int high=li.size();

        while(low<high){
            int mid=(low+high)/2;

            if (li.get(mid)>=target) high=mid;
            else low=mid+1;
        }
        return low;
    }

    int upper_bound(ArrayList<Integer>li,int target,int idx){
        int low=idx;
        int high=li.size();

        while(low<high){
            int mid=(low+high)/2;
            if (li.get(mid)>target) high=mid;
            else low=mid+1;
        }

        return low;
    }
}

/**
 * Your Router object will be instantiated and called as such:
 * Router obj = new Router(memoryLimit);
 * boolean param_1 = obj.addPacket(source,destination,timestamp);
 * int[] param_2 = obj.forwardPacket();
 * int param_3 = obj.getCount(destination,startTime,endTime);
 */