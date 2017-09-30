package Test;

import static org.junit.Assert.*;
import org.junit.Test;

import graph.WeightedGraph;

public class DijkstraTest {

  @Test
	public void sizeTest() {
    WeightedGraph wg = new WeightedGraph(1);
    assertEquals(3, wg.size());
	}

  @Test
	public void LabelTest() {
    WeightedGraph wg = new WeightedGraph(1);
    wg.setLabel(0, "v0");
    assertEquals("v0", wg.getLabel(0));
	}

  @Test
	public void IsEdgeTest() {
    WeightedGraph wg = new WeightedGraph(1);
    wg.addEdge(0, 0, 8)
    assertEquals(true, wg.isEdge(0, 0));
	}

  @Test
	public void NotIsEdgeTest() {
    WeightedGraph wg = new WeightedGraph(1);
    wg.addEdge(0, 0, -8)
    assertEquals(false, wg.isEdge(0, 0));
	}


  @Test
	public void getEdgeTest() {
    WeightedGraph wg = new WeightedGraph(1);
    wg.addEdge(0, 0, 8)
    assertEquals(8, wg.getEdge(0, 0));
	}

  @Test
	public void RemoveEdgeTest() {
    WeightedGraph wg = new WeightedGraph(1);
    wg.addEdge(0, 0, 8)
    assertEquals(true, wg.isEdge(0, 0));
    assertEquals(8, wg.getEdge(0, 0));

    wg.removeEdge(0, 0);
    assertEquals(false, wg.isEdge(0, 0));
    assertEquals(0, wg.getEdge(0, 0));
	}

  @Test
	public void neighborsTest() {
    WeightedGraph wg = new WeightedGraph(6);
    t.setLabel(0, "v0");
		t.setLabel(1, "v1");
		t.setLabel(2, "v2");
		t.setLabel(3, "v3");
		t.setLabel(4, "v4");
		t.setLabel(5, "v5");
		t.addEdge(0, 0, 2);
		t.addEdge(0, 5, 9);
		t.addEdge(1, 2, 8);
		t.addEdge(1, 3, 15);
		t.addEdge(1, 5, 6);
		t.addEdge(2, 3, 1);
		t.addEdge(4, 3, 3);
		t.addEdge(4, 2, 7);
		t.addEdge(5, 4, 3);
    wg.print();
    assertEquals(8, wg.getEdge(0, 0));
	}
}
