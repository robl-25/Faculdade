public abstract class CrossCompiler<T> {

  public final void crossCompile(T a) {
    collectSource(a);
    compileToTarget(a);
  }

  protected abstract void collectSource(T a);
  protected abstract void compileToTarget(T a);
}